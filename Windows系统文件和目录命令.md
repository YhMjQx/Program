# 一、目录和文件的应用操作

## 1.cd命令



```
cd /d D:\     //切换到D盘根目录，因为改变了驱动器，所以需要加上 /d  选项，注意一定不要将最后盘符后面的 \ 忘记了
```

![image-20230617153744547](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230617153744547.png)

文件访问过程中一般都是用的下斜杠 `\`

命令操作过程中一般都是用的上斜杠 `/`

```
C:\Users\Administrator>cd C:\    //如果没有改变驱动器号，就不需要加 /d 选项，注意一定不要将最后盘符后面的 \ 忘记了
```

**目录分为相对路径和绝对路径**

相对路径(以当前为起点)

​	`.`代表的是当前路径

![image-20230617154153346](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230617154153346.png)

​	`../`代表的是当前的上一级目录

![image-20230617154133272](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230617154133272.png)

绝对路径(以驱动器号为起点)

## 2.dir命令

![image-20230617154958120](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230617154958120.png)

**显示文件和文件列表的操作**

1.`dir`以数直列表的方式展现目录文件

![image-20230617155531269](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230617155531269.png)

2.`dir /w`以宽列表的形式展现目录文件

![image-20230617155609390](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230617155609390.png)

3.`/A:H`查看盘符下的隐藏文件

![image-20230617160617728](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230617160617728.png)

4.`/o:N `按字母顺序排列文件

`/O:-N`按字母顺序反着排列文件

![image-20230617161341366](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230617161341366.png)

常用的几种dir用法

```
dir
dir /a:h C:\	#查看C盘下的隐藏目录和文件
dir /o:-n C:\	#使用字母逆序方式查看文件
```

## 3.md或mkdir命令

**创建目录（文件夹），也可以直接创建多级子目录**

```
md 文件夹名称
md 文件夹名称1\文件夹名称2\文件夹名称3		当文件夹名称2不存在的时候会直接创建

```

## 4.rd命令

**删除目录（文件夹）**

```
rd 文件夹名称 		#直接使用rd，只能删除空目录
rd /s 文件夹名称 	#这样就可以删除多级目录
rd /s /q 文件夹名称 	#这样在删除多级目录的时候可以不用再次确认
```

![image-20230617170326266](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230617170326266.png)

## 5.move

**用于移动，重命名**

![image-20230617171536413](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230617171536413.png)

由于没有文件夹，于是我创建两个，但是发现是拒绝访问，查了资料之后发现是不能移动文件夹，而可以移动文件

注意：md命令只能创建文件夹文件

```
D:\>move hy.txt C:\ 	#将D盘中的hy.txt这个文件移动到C盘中
D:\>move C:\hy.txt C:\xhys.txt 	#把磁盘中hy.txt这个文件充命名为xhys.txt
```

## 6.copy

**用于复制文件，将一份或多份文件复制到另外一个位置**

```
D:\copy C:\3.txt D:\ 	#直接复制文件到指定目录
D:\copy 1.txt+2.txt 3.txt 	#将两个文件中的内容直接融合到新的文件中
```

## 7.xcopy

**一般用于复制目录**



语法和copy语法是一样的

## 8.del或者erase

```
D:\del 1.txt 	#删除D盘根目录中的1.txt文件
```

