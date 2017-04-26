# WeChat-GO 丢丢机器人

本项目基于 Node.js & Docker，本地运行此项目即可测试。

## 功能概述

WeChat-GO 将依靠微信机器人解决群主自动邀请加群、群内签到管理、群员发广告自动被踢出、群内每周统一分享技术文章、新加入群员受到欢迎以及更多还没有想到的功能。

> 如果您有任何疑问，请到[Issues][1] 反馈。

## 快速上手

* 第一步： Fork 或直接 Clone 本仓库至本地
* 第二步：确认本地是否搭建 Node.js 环境和 Docker 环境(详见下方“参考链接”)
* 第三步：进入 WeChat-GO 文件并进行安装

```
npm install
```

以上 npm 命令将自动安装依赖 qrcode-terminal 和 wechaty

```
"dependencies": {
    "qrcode-terminal": "^0.11.0",
    "wechaty": "^0.7.78"
},
```

* 第四步：docker run

```
docker run -ti --volume="$(pwd)":/bot --rm zixia/wechaty mybot.ts
```

> 如果您有任何疑问，请到[Issues][2] 反馈。

## TODO 计划列表

- [x] 群主自动邀请加群
- [x] 新加入群员受到欢迎
- [ ] 群内签到管理
- [ ] 群员发广告自动被踢出
- [ ] 群内每周统一分享技术文章

## 贡献指南

如果您想为 WeChat-Go 贡献代码，请采用 fork + pull request 方式，并在发起pr前先将master上超前的代码rebase到自己的分支上。

## 贡献者

* [韩亦乐][3]
* Waiting for U…

## 加入测试

丢丢机器人群内将及时测试最新的机器人，加我好友，注明“丢丢”或“WeChat-GO”，拉你入群。

![韩亦乐的个人微信号](public/我的微信号-缩略.png)

## 参考链接

* [wechaty][9]: 本项目依赖库
* [getting-started-wechaty][10]
* [Docker 从入门到实践][11]
* [Docker 入门实战][12]
* [Docker 入门教程][13]

## 开源许可

本项目采用 [GPL 许可证](http://www.gnu.org/licenses/gpl.html) 进行许可。

[1]:	https://github.com/icorvoh/WeChat-GO/issues
[2]:	https://github.com/icorvoh/WeChat-GO/issues
[3]:	https://github.com/icorvoh
[9]:	https://github.com/Chatie/wechaty
[10]:	https://blog.chatie.io/guide/2017/01/01/getting-started-wechaty.html
[11]:	https://www.gitbook.com/book/yeasy/docker_practice/details
[12]:	https://yuedu.baidu.com/ebook/d817967416fc700abb68fca1?fr=aladdin&key=docker&f=read###
[13]:	http://www.docker.org.cn/book/docker/what-is-docker-16.html