# web1

![image-20230611203804268](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230611203804268.png)

![image-20230611203834082](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230611203834082.png)

![image-20230611203839033](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230611203839033.png)

题目中也说了是查看源代码的题目，于是进来之后就直接Ctrl+U查看源代码就好了

# web2

![image-20230611204432712](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230611204432712.png)

这个题目是什么意思呢？？？

![image-20230611204453418](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230611204453418.png)

点进题目链接之后，告诉我无法查看源代码

但是！！！

我用了Ctrl+U之后，还是查看到了源代码

![image-20230611204643536](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230611204643536.png)

还有一种情况看题目，

![image-20230611204739742](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230611204739742.png)

通过在url头部添加view-source:

这个方法也是查看源代码的一种方式

![image-20230611205024599](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230611205024599.png)

[URL是Uniform Resource Locator的缩写，它是Web中的一个核心概念。URL是浏览器用来检索Web上公布的任何资源的机制。URL代表着统一资源定位符，它是Web上标准资源的地址。每个文件都有一个唯一的URL，它包含的信息指出文件的位置以及浏览器应该如何处理它。](https://developer.mozilla.org/zh-CN/docs/Learn/Common_questions/Web_mechanics/What_is_a_URL)[1](https://developer.mozilla.org/zh-CN/docs/Learn/Common_questions/Web_mechanics/What_is_a_URL)

但是这又是一种不懂得情况了，如果我在查看的时候添加了url就会是这样的源代码，我不懂，里面也没有flag

![image-20230611205305927](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230611205305927.png)

# web3

尝试了一下，Ctrl+U获取源代码失败

那么我就F12

发现这里面的源代码也的确看不到什么，然后在晚上看了看方法，说是在F12中的网络中

![image-20230611220300505](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230611220300505.png)

然后就找到了flag

![image-20230611220040921](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230611220040921.png)

[CTF Show中的flag藏在根目录下的一个文件中，读取文件内容接口过关。进入页面后，只有一句话“where is the flag?”。按照以往的经验，线索肯定就藏在前端页面的源代码中。右键检查或者按F12，进入开发者模式，或者直接右键查看网页源代码，源码的注释中提示了cmd，是在暗示我们利用代码执行漏洞。传入cmd参数，验证一下代码执行漏洞。成功显示出php信息，说明存在代码执行漏洞。接下来遍历目录glob()函数可以查找文件，返回一个文件数组，常配合通配符来遍历目录。可以看到目录下有两个文件，盲猜这个名字特殊的文件里面就有flag](https://developer.aliyun.com/article/848959)[1](https://developer.aliyun.com/article/848959)[2](https://blog.csdn.net/qq_51439282/article/details/120707741)[3](https://blog.csdn.net/miuzzx/article/details/104372662).

[代码执行漏洞是指应用程序本身过滤不严，用户可以通过请求将代码注入到应用中执行。](https://blog.csdn.net/weixin_45007073/article/details/113038152)[1](https://blog.csdn.net/weixin_45007073/article/details/113038152)[ 代码执行漏洞是调用系统命令的漏洞，命令执行漏洞是直接调用系统命令，又称为 os 命令执行漏洞。](https://www.cnblogs.com/backlion/p/9479159.html)[2](https://www.cnblogs.com/backlion/p/9479159.html)[ 代码执行漏洞是由于服务器对危险函数过滤不严导致用户输入的一些字符串可以被转换成代码来执行，从而造成代码执行漏洞。](https://juejin.cn/post/7111327575623860260)[3](https://juejin.cn/post/7111327575623860260)

## web3的第二种解法：

利用burp进行抓包，然后看返回包

![image-20230613230628349](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230613230628349.png)

由于我的edge浏览器无法使用bp代理，于是我将

![image-20230613230904507](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230613230904507.png)

这个页面的网页放在火狐中区抓包，我的火狐可以使用bp抓包

![image-20230613231017167](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230613231017167.png)

看到这个页面说明已经抓包成功了，现在就要进行返回包操作

![image-20230613231103072](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230613231103072.png)

Ctrl+R，发送给Repeater

![image-20230613231215086](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230613231215086.png)

点击放包

![image-20230613231439995](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230613231439995.png)

然后进入重发器，点击发送，就可以找到flag了

# web4

![image-20230613233634685](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230613233634685.png)

我们可以先查看源码，然后抓包查看报文是否有相关数据,但是我们会发现都没有Flag相关的东西.

 接下来我们可以尝试**查看robots.txt文件**，这个文件可能会泄露部分网站目录.

直接在该网址后面加上/robots.txt即可，看看哪些是可以爬取哪些是不可以爬取的

![image-20230613233820025](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230613233820025.png)

进来之后发现是这个样子，说明这个robots协议隐藏（或者说泄露了）了这个flagishere.txt文件，那么我们就继续在网页下爬取这个文件就好了

![image-20230613234003437](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230613234003437.png)

于是乎，就得到了flag

# web5

![image-20230614135726378](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230614135726378.png)

这个题在题目上已经给了提示，考点是php文件泄露，直接访问index.php,这样是查看该网页php泄露的文件

**phps文件**就是php的源代码文件，通常用于提供给用户（访问者）直接通过Web浏览器查看php代码的内容。

因为用户无法直接通过Web浏览器“看到”php文件的内容，所以需要用phps文件代替。用户访问phps文件就能看到对应的php文件的源码。

![image-20230614140026808](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230614140026808.png)

但是这种情况发现，什么都没有，于是我再在后缀上加一个s，直接保存下载这个泄露的PHP文件，

![image-20230614140139827](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230614140139827.png)

然后打开文件

![image-20230614140200823](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230614140200823.png)

即可获得flag

# web6

![image-20230614161031620](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230614161031620.png)

看题目中的提示

1.解压源码到当前目录，测试正常，收工

2.考察代码泄露，直接访问url/www.zip，获得flag

解压源码说明源码包在当前目录下，我们直接下载源码包即可

输入一下常见的源码包名字也就是www.zip，放在网址栏中，敲一个回车

![image-20230614190028133](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230614190028133.png)

![image-20230614190032996](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230614190032996.png)

打开这个压缩包

发现里面有两个文件

![image-20230614190125030](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230614190125030.png)

![image-20230614190137677](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230614190137677.png)

![image-20230614190145731](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230614190145731.png)

打开之后分别是这两个文件

我们可以看见flag{flag_here}，尝试提交，发现是错的，说明这并不是真的flag，这到底是怎么回事呢？？？粗略的解释如下：

在真正的开发过程中，就比如开发了一套系统，里面会包含一个敏感文件，在这里我们暂且称之为flag.txt，像这种txt文件的默认内容是aaa，然后这个开发团队将这个源码包开放下载，使得用户是可以任意使用这个文件的。那么如果我下载了这个系统，flag.txt可以任意修改

我得到的源码包里面有这个文件代表服务器上有这个文件，但是内容不一定就是原本的源码包中的文件

换句话说，我打开的文件也许是别人改过的文件，所以里面的内容不一定就是真正有效正确的，因此，我需要在网页中对这个文件进行访问（这个文件也是在开发状态下放出来的）

![image-20230614191652208](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230614191652208.png)

于是才能得到flag

# web7

![image-20230614205752497](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230614205752497.png)

看题目提示

1.版本控制很重要，但不要部署到生产环境更重要

2.考察git代码泄露，直接访问url/.git/index.php（我备注一下啊，这里的url就是指的是第一次进网页后的那个网址），所以url/.git/index.php的意思就是在最开始的哪个网址最后加上/.git/index.php就好了

![image-20230614210021693](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230614210021693.png)

但是直接访问

![image-20230614211732805](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230614211732805.png)

也是可以的，为什么可以这样呢？？？

是因为以.开头的文件夹在linux下属于隐藏文件，有的人在终端里面操作的话，可能就会看不见这个文件，错误得将该文件部署到了这个网站，造成开发的信息泄露

正如简介所说，在配置不当的情况下，可能会将“.git”文件直接部署到线上环境，这就造成了git泄露问题。

攻击者利用该漏洞下载.git文件夹中的所有内容。如果文件夹中存在敏感信息(数据库账号密码、源码等)，通过白盒的审计等方式就可能直接获得控制服务器的权限和机会！

# web8

这个题目在题目里的提示已经给的很明显了

![image-20230614222018044](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230614222018044.png)

1.版本控制很重要，但不要部署到生产环境更重要

2.考察信息svn泄露，直接访问url/.svn/

我的理解就是查看svn泄露的隐藏文件

![image-20230614222451412](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230614222451412.png)

# web9

![image-20230614231223756](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230614231223756.png)

这明显是一个vim泄露

也就是说vim环境下突然修改了文件，然后突然死机了，也就是会所在修改文件后未保存文件出意外导致突然退出编辑，然后vim环境会自动保存一个文件

临时文件是在vim编辑文本时就会创建的文件，如果程序正常退出，临时文件自动删除，如果意外退出就会保留，当vim异常退出后，因为未处理缓存文件，导致可以通过缓存文件恢复原始文件内容

以 index.php 为例 第一次产生的缓存文件名为 .index.php.swp
第二次意外退出后，文件名为.index.php.swo
第三次产生的缓存文件则为 .index.php.swn
注意：index前有 " . "

所以也就是说根据题目的体会四，我需要访问vim环境下的第一次意外退出的缓存文件，即/index.php.swp

![image-20230614231553451](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230614231553451.png)

然后就会自动下载一个文件

![image-20230614231613713](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230614231613713.png)

用记事本打开

![image-20230614231628961](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230614231628961.png)

就可以得到flag