var SLOW_TIME = 3000;

var CACHE_NAME = 'my-site-cache-v1';
var urlsToCache = [
  '/',
  '/main.css',
  '/main.js'
];

// 该文件在 Service Workers 中拥有相应的全局变量
// caches 指向 CacheStorage
// self 指向 ServiceWorkerGlobalScope
console.log(caches)
console.log(self)

self.addEventListener('install', function (event) {
  // 为安装事件定义回调，并决定想要缓存的文件
  console.log('Installed service worker');
  // 需要执行步骤：打开缓存、缓存文件、确认所有需要的资产是否缓存
  event.waitUntil(
    // 这是一个 promise 链
    caches.open(CACHE_NAME)
      .then(function(cache) {
        console.log('Opened cache');
        return cache.addAll(urlsToCache);
      })
  );
});

self.addEventListener('fetch', function(event) {
  event.respondWith(
  	// 以下方法检视请求，并从服务工作线程所创建的任何缓存中查找缓存的结果
    caches.match(event.request)
      .then(function(response) {
  	    console.log(event.request)
      	console.log(caches)
        // 如果发现匹配的响应，则返回缓存的值
        if (response) {
          return response;
        }
        return fetch(event.request);
      }
    )
  );
});

// 以下代码暂未连贯和实地测试

self.addEventListener('message', function(event) {
    var promise = self.clients.matchAll()
        .then(function(clientList) {
            var senderID = event.source ? event.source.id : 'unknown';

            if (!event.source) {
                console.log('event.source is null; we don\'t know the sender of the ' +
                    'message');
            }

            clientList.forEach(function(client) {

                if (client.id === senderID) {
                    return;
                }
                client.postMessage({
                    client: senderID,
                    message: event.data
                });
            });
        });


    if (event.waitUntil) {
        event.waitUntil(promise);
    }
});


self.addEventListener('activate', function(event) {
    event.waitUntil(self.clients.claim());
});

// 更新服务工作线程

self.addEventListener('activate', function(event) {

  var cacheWhitelist = ['pages-cache-v1', 'blog-posts-cache-v1'];

  event.waitUntil(
    caches.keys().then(function(cacheNames) {
      return Promise.all(
        cacheNames.map(function(cacheName) {
          if (cacheWhitelist.indexOf(cacheName) === -1) {
            return caches.delete(cacheName);
          }
        })
      );
    })
  );
});