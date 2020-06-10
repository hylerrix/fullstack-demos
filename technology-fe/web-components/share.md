# 拥抱 Web Components: 背景、实战与持续更新

* 本场分享定义的难度为初级——概念偏多、婉转道来。
* 本场分享希望达到的效果：Web Components 背景走一遍、Web Components 概念过一遍，第一个 Web Components 框架搭建第一个小 demo、持续关注线上的更新。
* 本场分享参考了大量的资料。

> 搭积木

## 1 - 入门

### 零、进击的前端框架，加速前端组件化进程

> HTML 标签本身算半个组件，table、input、select 都有默认的样式

> 前端组件化的历史背景

> * 前后端分离，REST 软件架构发展。
> * 传统开发方式(单体架构): 软件系统是整块应用，效率低、维护成本高，复杂度随业务增长呈指数级增长，常常"牵一发而动全身"。
> * 热插拔式化繁为简：
>   * 热插拔：允许用户在不关闭系统，不切断电源的情况下取出和更换损坏的硬盘、电源或板卡等部件，从而提高了系统对灾难的及时恢复能力、扩展性和灵活性等，例如一些面向高端应用的磁盘镜像系统都可以提供磁盘的热插拔功能。
>   * 后端逐步倾向于微服务——拆分成多个小服务，分别部署，降低了开发的复杂性、提高了系统的可伸缩性。
>   * 前端逐步倾向于前端 UI 组件化，当然，现在也多了前端微服务的概念。
>   * 业界早已有了实践：我们希望一个大且复杂的场景能够被分解成几个小的部分，彼此之间互不干扰，可以单独开发，单独维护。
> * Backbone、Angular、React、Vue 等以组件为主的优秀前端框架出现，前端组件化逐渐成为一种主流，一种共识。

前端组件化发展的几个阶段

* 交互少的静态页面时期：公共模块和 CSS
  * 开发者把不同模块的或者公共的 JS 和 CSS 放在不同的文件中，然后在页面引入并使用，这种方式也沿用至今。
* 早期动态页面时期：动态引入
  * 由于静态页面不能在页面上存储数据，阅读者也不满足于基本的页面交互，更希望页面能够活起来，且能够把交互的数据存储起来。
  * 于是出现了很多服务端技术，比如 ASP，JSP。这些技术的出现使得前端页面活起来了，用户可以根据自己的需求进行数据的交互。
  * 此时页面逻辑逐步复杂，也被公用出来：比如公共的页面头(header)和尾(footer)以及数据库的连接(DatabaseConn.jsp)等。
* 后端为主的 MVC 时期：Tag 标签
  * 早期动态页面时期的业务逻辑都写在页面上，随着逻辑的增多，页面越来越复杂
  * 以 servlet 为代表的 MVC 时代逐渐登上历史舞台，这时页面上的逻辑都被转入到 servlet 中，使得 View 层的表现更加简洁，也更加的易于阅读，从而达到了开发的分层。
  * 随着 Struts 以及 Spring 的出现，MVC 的开发方式达到鼎盛时期，前端 View 层的展现也变得越来越简单，没有了复杂的业务逻辑，前端的组件化方式主要是 taglib 标签，比如 jsp 标签，Struts 标签等，把 HTML 代码和业务逻辑打包成一个标签，然后使用者直接放置在想要的地方，就可以了。
  * 但这个时期，整个 WEB 应用的开发轻前端重后端，那些 taglib 标签也都是 JAVA 代码编写的。
* 前端 Ajax 时期：JS 大行其道
  * 服务端动态渲染消耗服务器性能，AJAX 的出现备受欢迎，服务端只用专注提供数据。
  * 这时出现了 JQuery-UI， easy-UI，miniUI 以及大名鼎鼎的 ExtJS。
  * 组件共用起来很复杂。
* 前端 MV* 时期：自定义组件
  * 想要修改这些（ExtJS，miniUI）JS 框架中的组件是非常困难的，因此开发者希望能够很容易的自定义一些组件，而且可以让开发者将已经存在的组件进行封装。
  * 这时 npm 以及 bower 这些包管理库也出现，开发者可以很容易的将自己开发的组件 publish 到这些库中，在使用时只要把他们下载下来（比如 npm install）就可以直接使用。
  * Backbone、Angular、React、Vue 等框架逐步成为潮流。
* 以上的组件化基本以 HTML 和 JS 为主，CSS 的组件化——less 和 sass
  * 最早的组件化尝试是把公共的 CSS 样式写成一个个公共 class，但阅读性就变得困难了，也不容易修改。
  * less 和 sass 出现之后，使得 CSS 的编程可以定义变量，可以实现继承，CSS 内容的结构也变得更加清晰。
  
前端组件化的四原则

* 标准性：任何一个组件都应该遵守一套标准，可以使得不同区域的开发人员据此标准开发出一套标准统一的组件。
* 组合性：组件之间应该是可以组合的。
* 重用性：任何一个组件应该都是一个可以独立的个体，可以使其应用在不同的场景中。
* 可维护性：任何一个组件应该都具有一套自己的完整的稳定的功能，仅包含自身的，与其它组件无关的逻辑。

传统开发与组件化开发：
* 对比（标准性、阅读性、复用性、代码冗余、开发效率、维护成本）：
  * 传统前端开发：（难统一、难、难、多、低、高）
  * 组件化开发：（统一、易、易、基本没冗余、高、低）
* 对前端开发者的要求逐步加深：
  * 传统前端开发：只要求开发者懂 HTML，JS，CSS
  * 组件化开发：要求开发者掌握 less，sass，或者 ES6 等的语法，以及 Webpack，glup 等的前端打包以及构建工具。
* 前端生态逐渐完善
  * jade、less、scss、typeScript 和 webpack 等工具的完善，前端的组件化开发效率已经有了很大的提升。
  * 如果你需要 SEO，React 和 Vue 的 SSR 框架 Next.js 和 Nuxt.js 更是提供了开箱即用的集成方案，也使开发“同构页面系统“（Google It）变得更加简单。

组件化的开发一直是有共识，但没有一个通用的标准

### 一、Web Components 标准呼之欲出

Web Component 就是网页组件式开发的技术规范。

使用 Web Components 的优点：

* 管理和使用非常容易。加载或卸载组件，只要添加或删除一行代码就可以了。
* 定制非常容易。组件往往留出接口，供使用者设置常见属性，比如上面代码的 heading 属性，就是用来设置对话框的标题。
* 组件是模块化编程思想的体现，非常有利于代码的重用。标准格式的模块，可以跨平台、跨框架使用，构建、部署和与其他UI元素互动都有统一做法。
* 组件提供了 HTML、CSS、JavaScript 封装的方法，实现了与同一页面上其他代码的隔离。

Web Components 不是单一的规范，而是一系列的技术组成，包括 Template、Custom Element、Shadow DOM、HTML Import 四种技术规范。使用时，并不一定这四者都要用到。其中，Custom Element 和 Shadow DOM 最重要，Template 和 HTML Import 只起到辅助作用。

### A - Custom Elements



### B - HTML Imports

### C - HTML Templates

#### 概念

<template>元素，基本上可以确定是2013年才出现的，见名知意，模板元素，

以前我们在HTML中嵌入模板HTML，往往是类似这样的写法：

```
<script type="text/template">
// ...
</script>
```

#### 实战

1 - 检查是否支持 template 标签

```
function supportsTemplate() {
  return 'content' in document.createElement('template');
}

if (supportsTemplate()) {
  // 支持
} else {
  // 不支持
}
```

2 - 定义一个 template 标签作为 template——模板

```
<template id="profileTemplate">
  <div class="profile">
    <img src="" class="profile__img">
    <div class="profile__name"></div>
    <div class="profile__social"></div>
  </div>
</template>
```

3 - 直接修改 template 模板

```
var template = document.querySelector('#profileTemplate');
template.content.querySelector('.profile__img').src = 'profile.jpg';
template.content.querySelector('.profile__name').textContent = 'Barack Obama';
template.content.querySelector('.profile__social').textContent = 'Follow me on Twitter';
document.body.appendChild(template.content);
```

4 - 克隆 template 模板，修改克隆的

```
var clone = document.importNode(template.content, true);
document.body.appendChild(clone);
```

document.importNode 方法用于克隆外部文档的 DOM 节点。克隆节点之后，还必须用appendChild方法将其加入当前文档，否则不会显示。

5 - 关于样式

宿主样式:host：

* 接受 template 插入的元素，叫做宿主元素（host）。在 template 之中，可以对宿主元素设置样式。
* 在shadow DOM中利用:host定义宿主的样式，当然用户可以在主文档中覆盖这个样式。
* :host 是伪类选择器（Pseudo Selector）,:host或者 :host(*)是默认给所有的宿主添加样式，或者单独给一个宿主添加样式，即通过:host(x)，x可以是宿主的标签或者类选择器等。
* 另外:host还可以配合:hover、:active等状态来设置样式

```
  :host {
    background: #f8f8f8;
  }
  :host(:hover) {
    background: #ccc;
  }
```

::shadow：

* 原则上来说，影子边界保证主 DOM写的 CSS 选择器和 JavaScript 代码都不会影响到Shadow DOM。
* 但你可能会想打破影子边界的所谓保证，主文档能够给Shadow DOM添加一些样式，这时可以使用::shadow。

/deep/：

::shadow 选择器的一个缺陷是他只能穿透一层影子边界，如果你在一个影子树中嵌套了多个影子树，那么使用 /deep/ 。

::content

通过 <content> 标签把来自主文档并添加到 shadow DOM 的内容被称为分布节点。分布节点的样式渲染需要用到 ::content。即使分布节点为em标签，直接写 em {} 不生效，应该写成::content > em {}。
                                                


### D - Shadow DOM

#### 无意中已经接触过 Shadow DOM

为什么只用video标签包裹着source标签，就可以完成一系列视频功能：播放/暂停按钮、进度条、视频时间显示、音量控制等等？

```
<video controls autoplay name="media" width="500">
    <source id="mp4" src="http://7ryl2t.com2.z0.glb.qiniucdn.com/572ffc37a2e5a.mp4" type="video/mp4">
</video>
```

在浏览器chrome中打开，然后打开 Chrome 的开发者工具，点击右上角的“Settings”按钮，勾选“Show user agent shadow DOM”。

#shadow-root称为影子根，可以看到它在video里面，换句话说，#shadow-root寄生在video上，所以video此时称为影子宿主。可以看到上图有两个#shadow-root，这是因为#shadow-root可以嵌套，形成节点树，即称为影子树（shadow trees）。影子树对其中的内容进行了封装，有选择性的进行渲染。这就意味着我们可以插入文本、重新安排内容、添加样式等等。如下所示：

#### 开始使用 Shadow DOM


主要为了解决dom对象的封装，通常的dom，其js行为和css样式极易受到别的代码的干扰，但shadow dom规定了只有其宿主才可定义其表现，外部的api是无法获取到shadow dom中的东西。

由于shadow dom是影子元素，因此其必须捆绑一个宿主元素，宿主元素事实上成为了“傀儡”，宿主元素的内容将被隐藏，而shadow dom的内容将展示出来，以下是一个例子：

```
html:
<div id="con">
    没什么卵用的文字
</div>

js:
var host = document.querySelector('#con');
var root = host.attachShadow({mode:'open'});//为宿主附加一个影子元素

root.innerHTML = "我来自shadow dom";//为影响元素附上内容，shadow dom的api和普通dom的大致相同
```

通过chrome的devtools，可以看到宿主的原内容以及背后的shadow dom

前面说了，shadow dom可以实现dom的隔离，比如样式的封装，那么如何实现呢？shadow规定了一种名为template的标签，这种标签类似我们经常用的<script type='tpl'>，它不会被解析为dom树的一部分，template的内容可以被塞入到shadow dom中并且反复利用，在template中可以设置style，但只对这个template中的元素有效，看下示例：

```$xslt
html:
<style>
span {
  background-color:blue;/*设置页面所有span背景为蓝色，然而对shadow dom没什么卵用*/
}
</style>
<div id="con">
    没什么卵用的文字
  </div>
   <template id="tpl">
     <style>
       span {
         color:red;
       }
     </style>
     <span>hello world</span>
   </template>

js:
var host = document.querySelector('#con');
var root = host.attachShadow({mode:'open'});

var con = document.getElementById("tpl").content.cloneNode(true);

root.appendChild(con);
```

效果截图：

<span style='color:red'>hello world</span>

可以看到，template的内容被塞入到宿主，并且其文案被设置为红色，而body 中对 span 设置为蓝色背景却没有生效；另外这里要注意document.getElementById("tpl").content中的content属性，它是template标签的特有属性，你可以通过嗅探该属性来判断浏览器是否支持shadow dom和template标签。

#### Shadow Dom Slot

最新的shadow dom草案支持了一个叫slot标签的东西，slot是一个插槽，一个坑位，可以在template中定义坑位，然后宿主中的内容可以标记属于哪一个坑位，这样一个萝卜一个坑，宿主的内容就会被正确地插入到template所标记的位置去，

```
html:
<div id="con">
    没什么卵用的文字
    <span slot="main1">
      坑位1
    </span>
    <span slot="main2">
      坑位2
    </span>
    没什么卵用的文字 </div>
  <template id="tpl">tpl begin
    <slot name="main1">
    </slot>
    <slot name="main2">
    </slot>
    tpl end
      </template>

js:
var host = document.querySelector('#con');
var root = host.attachShadow({mode:'open'});

var con = document.getElementById("tpl").content.cloneNode(true);

root.appendChild(con);
```

最终的效果是

tpl begin 坑位1 坑位2 tpl end

可以看到，宿主中的两个span分别插入到了其标记的slot坑位中。在slot出现之前，仍然可以实现类似的功能，只不过标签名叫content。

slot标签仅仅是一个占位符而已，其最终会被宿主标记了该位置的内容替换（注意是替换，而不是插入），因此没必要对slot标签设置样式，这就是为啥chrome 53忽略其样式的原因，无独有偶，最新版的ios 10默认浏览器也会隐藏slot，因为slot中并不需要显示任何东西。

#### Shadow DOM JavaScript

### 回顾新特性

我们都用了哪些不常见的语法
* document.importNode
* template.content.querySelector


## 2 - 选个框架实战

## 持续更新

https://github.com/hylerrix