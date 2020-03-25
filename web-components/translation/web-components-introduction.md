# 步入 Web Components

> [原文链接](https://www.webcomponents.org/introduction)

> 翻译状态: 一大半

## Web Components 是什么？

Web Components 建立在现有的 Web 标准上，提供多种可以创建自定义、可重用且易封装地 HTML 标记的 API，以便开发者在网页或 Web 应用程序中使用。构建在 Web Components 标准上的自定义组件和小部件，可以流畅的运行在主流浏览器中，并且可以集成在任何能操作 HTML 文档的 JavaScript 库或框架中。

目前 HTMl 和 DOM 规范也逐渐支持 Web Components 提出的新功能，便于让 Web 开发人员使用封装样式和自定义行为的新元素轻松扩展 HTML。

## 技术规范

Web Components 基于如下四个主要规范：

### Custom Elements

[Custom Elements 规范](https://w3c.github.io/webcomponents/spec/custom/) 为设计和使用新类型 DOM 元素奠定了基础。

### Shadow DOM

[Shadow DOM 规范](https://w3c.github.io/webcomponents/spec/shadow/) 定义了如何在 Web 组件中使用封装样式和标记。

### HTML Imports

[HTML Imports 规范](https://w3c.github.io/webcomponents/spec/imports/) 定义了 HTML 文档在其他 HTML 文档中的包含和重用规则。

### HTML Template

[HTML Template 规范](https://html.spec.whatwg.org/multipage/scripting.html#the-template-element/) 定义如何声明一个在页面加载时未使用但在运行时实例化的 HTML 片段的一些规则。

## 如何编写一个 Web Component ？

本站点([webcomponents.org](https://www.webcomponents.org/)提供了可在 Web 页面和 Web 应用程序中使用的一些新 HTML 元素。

使用自定义元素就像导入它一样简单，只需在 HTML 文档中书写一个新标记。例如，你可以这样使用[Emoji 雨](https://www.webcomponents.org/element/notwaldorf/emoji-rain)元素：

```
<link rel="import" href="../emoji-rain/emoji-rain.html">
...
<emoji-rain active></emoji-rain>
```

还有很多种方法可以安装自定义元素到你的项目中。当你找到了一个想要使用的自定义元素，多从它的 README 文档学习如何安装使用。现在大多数自定义元素都可以通过 Bower 来安装，Bower 还可以解决组件间的依赖关系。更详细的 Bower 文档记得访问 Bower.io。

在上述[Emoji 雨](https://webcomponents.org/element/notwaldorf/emoji-rain)的 README 文档中，介绍了使用 Bower 来安装它的方法：

```
mkdir emoji-rain-demo && cd emoji-rain-demo
bower install emoji-rain
```

## 如何定义一个新的 HTML 元素？

本节使用 Web Components 规范中跨浏览器 v1 版本中的语法来介绍。

我们可以在 JavaScript 中使用全局的 customElements 对象来定义一个新的 HTML 元素及其标记，并将标记名称作为第一个参数传入 customElements.define()。我们还可以在 JavaScript 中拓展基本的 HTMLElement 类。
 
例如，我们可以这样定义一个移动端的抽屉面板 `<app-drawer>`：

```
class AppDrawer extends HTMLElement {...}
window.customElements.define('app-drawer', AppDrawer);
```

Custom Elements V0 版本中曾使用 document.registerElement() 来创建一个新的 HTML 元素：

```
var XFoo = document.registerElement('x-foo');
document.body.appendChild(new XFoo());
```

更多的内容可以直接访问 [Custom Elements V0 版本](https://www.html5rocks.com/en/tutorials/webcomponents/customelements/)，此时我们可以通过写入如下标记来实例化这个组件：

```
<app-drawer></app-drawer>
```

使用自定义元素与直接使用传统的 <div> 标签或其他任何标签并没什么不同之处。现在我们可以在页面中声明组件的实例，并交给 JavaScript 动态的创建和添加相应的事件侦听器了。

```
<script>
// 通过 JavaScript 的 API 接口来创建一个组件
var newDrawer = document.createElement('app-drawer');
// 将这个组件添加到页面中
document.body.appendChild(newDrawer);
// 给这个组件绑定相关事件
document.querySelector('app-drawer').addEventListener('open', function() {...});
</script>
```

## 创建并使用一个 shadow root

This section describes the syntax for creating shadow DOM with the new cross-browser version (v1) of the shadow DOM specification. Shadow DOM is a new DOM feature that helps you build components. You can think of shadow DOM as a scoped subtree inside your element.

A shadow root is a document fragment that gets attached to a "host" element. The act of attaching a shadow root is how the element gains its shadow DOM. To create shadow DOM for an element, call element.attachShadow():

```
const header = document.createElement('header');
const shadowRoot = header.attachShadow({mode: 'open'});
shadowRoot.innerHTML = '<h1>Hello Shadow DOM</h1>'; // Could also use appendChild().
// header.shadowRoot === shadowRoot
// shadowRoot.host === header
```

Version 0 of the shadow DOM specification provided a slightly different method for creating shadow DOM:

```
var root = host.createShadowRoot();
```

See this article on 【shadow DOM v0](https://www.html5rocks.com/en/tutorials/webcomponents/shadowdom/) for more information. See also [Hayato Ito's comparison of v0 and v1 of the shadow DOM specification](http://hayato.io/2016/shadowdomv1/).

## 一些用于构建 Web Components 的库

Many libraries already exist that make it easier to build web components. To dive in and create your own components, here are some you can try out:

* [Bosonic](https://bosonic.github.io/) is a collection of components designed to meet the everyday needs of web developers.
* [Polymer](https://www.polymer-project.org/) provides a set of features for creating custom elements.
* [SkateJS](https://github.com/skatejs/skatejs/) is a JavaScript library for writing web components with a small footprint.
* [Slim.js](http://slimjs.com/) is an opensource lightweight web component library that provides data-binding and extended capabilities for components, using es6 native class inheritance.
* [Stencil](https://stenciljs.com/) is an opensource compiler that generates standards-compliant web components.
* [X-Tag is](https://x-tag.github.io/) an open source JavaScript library that provides an interface for component development.