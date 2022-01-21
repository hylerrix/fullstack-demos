# 拥抱 Web Components: 背景、实战与持续更新

> 概念区分：Web Components、Web Component
> 一些 HTML 类：HTMLElement、Element
> DOM String

## 待整理

### HTMLELement 类

HTMLElement 接口表示所有的 HTML 元素。一些 HTML 元素直接实现了 HTMLElement 接口，其它间接实现 HTMLElement 接口。

***HTMLElement 属性***

继承自父接口 Element 和 GlobalEventHandlers 的属性

属性名称	属性类型	Description
* HTMLElement.accessKey	DOMString	获取/设置元素访问的快捷键
* HTMLElement.accessKeyLabel	DOMString	返回一个包含元素访问的快捷键的字符串（只读）
* HTMLElement.contentEditable	DOMString	获取/设置元素的可编辑状态
* HTMLElement.isContentEditable 只读	Boolean	表明元素的内容是否可编辑（只读）
* HTMLElement.contextMenu	HTMLMenuElement	设置/获取元素的右键菜单
* HTMLElement.dataset 只读	DOMStringMap	获取元素的自定义属性，是一个对象（key-value，只读）
* HTMLElement.dir	DOMString	获取/设置元素的方向，可选的值有：ltr，rtl，auto
* HTMLElement.draggable	Boolean	设置/获取元素是否可以拖拽
* HTMLElement.dropzone 只读	DOMSettableTokenList	 
* HTMLElement.hidden	Boolean	获取/设置元素是否隐藏
* HTMLElement.itemScope 	Boolean	 
* HTMLElement.itemType 只读	DOMSettableTokenList	 
* HTMLElement.itemId 	DOMString	 
* HTMLElement.itemRef 只读	DOMSettableTokenList	 
* HTMLElement.itemProp 只读	DOMSettableTokenList	 
* HTMLElement.itemValue 	object	 
* HTMLElement.lang	DOMString	获取/设置元素属性、文本、内容的语言
* HTMLElement.offsetHeight 只读	double	元素自身可视高度加上上下border的宽度
* HTMLElement.offsetLeft只读	double	元素自己border左边距离父元素border左边或者body元素border左边的距离
* HTMLElement.offsetParent只读	Element	元素的父元素，如果没有就是body元素
* HTMLElement.offsetTop只读	double	元素自己border顶部距离父元素顶部或者body元素border顶部的距离
* HTMLElement.offsetWidth只读	double	元素自身可视宽度加上左右border的宽度
* HTMLElement.properties 只读	HTMLPropertiesCollection	 
* HTMLElement.spellcheck	Boolean	 
* HTMLElement.style	CSSStyleDeclaration	获取/设置元素的style属性
* HTMLElement.tabIndex	long	获取/设置元素的tab键控制次序
* HTMLElement.title	DOMString	获取/设置元素的title属性
* HTMLElement.translate 	Boolean	获取/设置元素是否可以被翻译

以 on 前缀形式开头的事件属性通常在 GlobalEventHandlers 上定义，由 HTMLElement 实现，但也有一些只定义于 HTMLElement 上。

* HTMLElement.onTouchStart Returns the event handling code for the touchstart event.
* HTMLElement.onTouchEnd Returns the event handling code for the touchend event.
* HTMLElement.onTouchMove Returns the event handling code for the touchmove event.
* HTMLElement.onTouchEnter Returns the event handling code for the touchenter event.
* HTMLElement.onTouchLeave Returns the event handling code for the touchleave event.
* HTMLElement.onTouchCancel Returns the event handling code for the touchcancel event.

***HTMLElement 方法***

继承自父元素 Element 的方法

Name & Arguments	Return	Description
HTMLElement.blur()	void	元素失去焦点
HTMLElement.click()	void	触发元素的点击事件
HTMLElement.focus()	void	元素获得焦点
HTMLElement.forceSpellCheck() 	void	

***规范*** 

Specification	Status	Comment

> CSS Object Model (CSSOM) View Module
HTMLElement	Working Draft	
添加如下属性：
offsetParent，offsetTop，offsetLeft，offsetWidth，offsetHeight

> HTML Living Standard
HTMLElement	Living Standard	
添加如下属性:
translate，itemScope，itemType，itemId，itemRef，itemProp，properties，itemValue。
添加如下方法：
forceSpellcheck()，
将 onXYZ 属性移动到了GlobalEventHandlers接口上并从该接口继承了该属性

> HTML5
HTMLElement	Recommendation	
添加了如下属性:
dataset, hidden, tabindex, accessKey, accessKeyLabel, draggable, dropzone, contentEditable, isContentEditable, contextMenu, spellcheck, commandType, commandLabel, commandIcon, commandHidden, commandDisabled, commandChecked, style，和所有的 onXYZ属性
移动id和classname属性到Element接口上

> Document Object Model (DOM) Level 2 HTML Specification
HTMLElement	Obsolete	在 Document Object Model (DOM) Level 2 HTML Specification基础上没有任何改变

> Document Object Model (DOM) Level 1 Specification
HTMLElement	Obsolete	初始定义

### Element 类

Element 是非常通用的基类，所有 Document 对象下的对象都继承它。这个接口描述了所有相同种类的元素所普遍具有的方法和属性。这些继承自 Element 并且增加了一些额外功能的接口描述了具体的行为，例如：HTMLElement 接口是所有 HTML 元素的基础接口，而 SVGElement 接口是所有 SVG 元素的基本接口。

### DOM String

DOMString 是一个 UTF-16 字符串，由于 JavaScript 已经使用了这样的字符串，所有 DOMString 直接映射到一个 String。

将 null 传递给接受 DOMString 的方法或参数时通常会把其 stringifies 为"null"。

> 概念区分：Web Components、Web Component

## 前端组件化发展路程

### 进击的前端框架

#### 慢速

* jQuery 最初诞生于 2006 年 8 月，作者是 John Resig。
* 10 多年前，网页开发者（当时还没有“前端”这个概念）深受浏览器不兼容性之苦。
* 以 jQuery 为代表的一批 JavaScript 库/框架应运而生：
  * Dojo：像 jQuery 一样是主打通用性
  * jQuery
  * MooTools
  * Prototype：像 jQuery 一样是主打通用性
  * Yahoo! User Interface Library (YUI)：走更专业化的路线，组件化
  * Script.aculo.us：走更专业化的路线，动画交互
* 以上框架都提供了如下特性
  * 语法糖：链式调用、实用函数
  * 选择元素：基于各种标准选择符和库自定义的选择符，以及通过回调进行筛选
  * 操作 DOM：创建和操作元素，乃至各种属性操作
  * 处理事件：ready 事件及各种注册和触发事件的方法，乃至委托
  * 动画：基于 animate 的 CSS 属性动画，以及内置动画方法
  * Ajax：封装原生的 XMLHttpRequest API，简化请求方法及回调处理
* 为什么选择 jQuery：跨浏览器、简单高效、稳定可靠、插件丰富
* JavaScript DOM 脚本编程艺术（第2版） 2010 年出版
* JavaScript: The Definitive Guide, 6th，2011 年出版，第 19 章整整 64 页介绍 jQuery

#### 快速

* 从 ES6 起，ECMAScript 也进入了快速迭代、每年发一版的节奏。ES7、ES8，以及 ES9，每次都会给这门语言注入更强大的语言特性。
* Node.js、Babel 等服务端运行时及转移工具的出现，前端工程化的基础。
* 2012 年，@李松 翻译的《JavaScript 宝座：七大框架论剑》
  * Backbone(库)
  * Knockout(库)
  * Spine(库)
  * CanJS(库)
  * Ember(框架)
  * AngularJS(框架)
  * Batman(框架)
  * Meteor(框架)
* 库和框架的区别
  * 库：插到既有架构中，补充特定功能
  * 框架：提供一个架构
* 2012 年后，七大框架逐步被新三大框架取代，从后“刀耕火种”时代的“农业文明”，逐渐进化为以大规模、可扩展、规范化、自动化为特征的准“工业文明”。
  * 先是谷歌主打 SPA 的 Angular 一枝独秀。
  * 不久，脸书的 React 诞生，高歌猛进。
  * 集各家所长、简单易用的 Vue 横空出世。

  
### 越来越成熟的前端组件化

> 在 Web Components 标准出现前，各框架对前端组件化有着自己的实践和探索。

> 这个由各方自己实现，逐步确定为标准的技术推进过程——模块打包机制的发展也很像。

Angular Directive

Angular2 components

React components

Vue?

x-tag

polymer

## Web Components 概述

* 为什么要提出？
* 解决了哪些问题？
* 借鉴、融合了哪些思想？
* 浏览器的支持情况？

### 什么是组件

> 组件的要点：复用、生命周期、封装隔离、跨平台、构建部署、定制、搭积木

各种网站往往需要一些相同的模块，比如日历、调色板等，这些模块就被称为组件，Web Components 就是网页组件式开发的技术规范。
组件。

采用组件进行网站开发的优点：

* 管理和使用非常容易。安装、卸载组件，只要添加或者删除一行代码就可以了。
* 定制容易，有各种接口规范来方便使用。
* 组件是模块化编程思想的提现，非常有利于代码的重用。标准格式的模块，可以跨平台、跨框架使用，构建、部署和与其他 UI 元素互动都有统一做法。
* 组件提供了 HTML、CSS、JavaScript 封装的方法，实现了与同一页面上其他代码的隔离。

### Web Components 暴露出的 API 列表？

document.registerElement
document.createElement('')：创建 template 标签，该 template 模板存在于 DOM 之中，但是在页面中不可见。
document.importNode()：用于克隆外部文档的 DOM 节点。；比如克隆 template 节点，可实现多次使用模板。

## 深入浅出 Web Components 四大部分

Web Components 是以下四种技术规范的组成，并不一定四者都需要用到。其中，Custom Element 和 Shadow DOM 最重要，Template 和HTML Import 只起到辅助作用。

* [Custom Elements - W3C](https://w3c.github.io/webcomponents/spec/custom/)
* [HTML Imports - W3C](https://w3c.github.io/webcomponents/spec/imports/)
* [HTML Templates - WHATWG](https://html.spec.whatwg.org/multipage/scripting.html#the-template-element)
* [Shadow DOM - W3C](https://w3c.github.io/webcomponents/spec/shadow/)

### 兼容性

#### 测试是否支持 template 标签

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

#### 测试是否支持自定义元素。

```
if ('registerElement' in document) {
  // 支持
} else {
  // 不支持
}
```

#### 测试是否支持 HTML Import

```
function supportsImports() {
  return 'import' in document.createElement('link');
}

if (supportsImports()) {
  // 支持
} else {
  // 不支持
}
```

### Custom Elements

HTML(HTML5) 预定义的网页元素有哪些？hr、br、h1、p、section、canvas。。。

提供一种方式让开发者可以自定义 HTML 元素，包括特定的组成、样式和行为。

* 如何自定义组成
* 如何自定义样式
* 如何自定义行为

自定义元素的标签名：自定义网页元素的标签名必须含有连字符（-），这是因为浏览器内置的的HTML元素标签名，都不含有连字符，这样可以做到有效区分。一个或多个都可，不能是以下。
  * annotation-xml
  * color-profile
  * font-face
  * font-face-src
  * font-face-uri
  * font-face-format
  * font-face-name
  * missing-glyph

#### 知识储备

HTMLElement
HTMLInputElement

#### 要点概述

registerElement

* HTMLInputElement 可理解为 input DOM 元素实例化时的构造函数，基础是 HTMLElement
* 使用 document.registerElement 来注册一个标签
  * 第一个参数：标准中提供 namespace 的支持，这里是标签名。
  * 第二个参数：标签相关的配置，主要提供一个 prototype，这个原型对象是以 HTMLElement 等的原型为基础创建的对象。

生命周期和回调——组件需要安装、卸载等

* 自定义元素经历的生命周期
  * 注册前创建
  * 注册自定义元素定义
  * 在注册后创建元素实例
  * 元素插入到 document 中
  * 元素从 document 中移除
  * 元素的属性变化时
* 指定对应的生命周期回调来位自定义元素添加各种自定义行为，这些生命周期回调包括了：
  * createdCallback 自定义元素注册后，在实例化之后会调用，通常多用于做元素的初始化，如插入子元素，绑定事件等。
  * attachedCallback 元素插入到 document 时触发。
  * detachedCallback 元素从 document 中移除时触发，可能会用于做类似 destroy 之类的事情。
  * attributeChangedCallback 元素属性变化时触发，可以用于从外到内的通信。外部通过修改元素的属性来让内部获取相关的数据并且执行对应的操作。 这个回调在不同情况下有对应不同的参数：设置/修改/删除属性时。

拓展原有元素

* Web Components 标准提供了一种扩展现有标签的方式，使用 is 属性来声明一个扩展的类型。
* createElement、createElementNS

逐步向 ES6 靠拢

* 更加的 OO
  * 从原本的扩展 prototype 来定义元素调整为建议使用 class extends 的方式
  * 注册自定义元素接口调整，更加方便使用，传入 type 和 class 即可
  * 生命周期回调调整，createdCallback 直接用 class 的 constructor
* 原本的生命周期回调调整为新的
  * constructor in class 作用相当于原本的 createdCallback
  * connectedCallback 作用相当于 attachedCallback
  * disconnectedCallback 作用相当于 detachedCallback
  * adoptedCallback 使用 document.adoptNode(node) 时触发
  * attributeChangedCallback 和原本保持一致
* connect 事件和插入元素到 document 有些许区别，主要就是插入元素到 document 时，元素状态会变成 connected，这时会触发 connectedCallback，disconnect 亦是如此。
  
### HTML Imports

> 模板引擎

### HTML Templates

> solo、vue

接收 template 插入的元素，叫做宿主元素 host，template 之中可对宿主元素设置样式
  * :host(:hover) {}

### Shadow DOM

## Web Components 学习生态

### Web Components 简单介绍

Web Components 时什么？为什么要推荐使用它？所有的答案都在这篇文章中。

### Web Components Polyfills

让 Web Components 能运行在各大主流浏览器中——CHROME、OPERA、FIREFOX、SAFARI 7+、EDGE/IE11+

### Web Components 资源库

这里收集可以帮助我们构建 Web Components 的工具和样板

### Web Components 社区

### 第三方库

## 如何更好的阅读 Web Components 官方英文文档？

## Demo 实战

> 之后重新整理前缀编号

* 01-custom-elements
* 02-html-imports
* 03-html-templates
* 04-shadow-dom

## 临时疑问/待实战

* <link rel="import" href="my-dialog.htm">  <my-dialog heading="A Dialog"></my-dialog>
* Web Components 的 SSR 服务端渲染？
* 如何过渡到 Web Components？在主流框架中引入、从零安装使用、通过 Web Components 框架引入、考虑项目的浏览器兼容性目标

## 灵感，未来可拓展话题

* 前端框架演进史

## 参考资料

- [ ] [前端组件化](https://juejin.im/entry/58ad40482f301e006be3b3cd)
- [ ] [WebComponents.org](https://www.webcomponents.org/)
- [ ] [W3C Web Components - 官方文档](https://github.com/w3c/webcomponents)
- [ ] [Web Components 是个什么样的东西 - 掘金](https://juejin.im/post/57c40fd3128fe1005fd4629a)
- [ ] [Web Components - 阮一峰](http://javascript.ruanyifeng.com/htmlapi/webcomponents.html)
- [ ] [Web Components 整理及分享 - 简书](https://www.jianshu.com/p/e8994b92bb7a)
- [ ] [HTML5 <template>标签元素简介](https://www.zhangxinxu.com/wordpress/2014/07/hello-html5-template-tag/)
- [ ] [浅谈 shadow dom 中的 template 和 slot](https://www.jianshu.com/p/9293cac60920)
- [ ] [神奇的Shadow DOM](https://aotu.io/notes/2016/06/24/Shadow-DOM/index.html)
- [X] [再见 jQuery，我的老朋友](https://juejin.im/post/5b5af8565188251b186bcfcb)
- [X] [JavaScript 宝座：七大框架论剑](http://www.ituring.com.cn/article/8108)