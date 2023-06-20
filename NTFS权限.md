# NTFS权限

## 一、NTFS权限

1.文件系统

- Windows
  - 早期Windows上使用 FAT16或FAT32
  - 目前的windows操作系统基本上基本使用的是NTFS文件系统
    - ACL（访问控制列表，设置权限）
    - EFS（加密文件系统,Bitlocker）
    - 压缩及磁盘配额
  - ReFS文件系统
- Linux
  - swap：交换文件系统，主要是将磁盘的一部分空间划为内存使用
  - ext4:

文件系统转换

```powershell
#将自己的FAT文件系统的U盘转换为NTFS文件系统的U盘
C:\>conver H:/fs:ntfs 		//H - 表示磁盘的驱动器号（需要转换的盘符）
```

早期的FAT文件系统不支持单个大于4GB的大文件

## 二、文件权限

1.设置文件权限

- 读取数据
- 写入数据
- 附加数据
- 删除
- 执行

案例：我们让张三对一个文件有访问的权限但是没有修改的权限，那么就需要删除允许他修改文件的组

![image-20230620171543109](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230620171543109.png)

但是i我们发现因为一些继承关系我们删不掉

![image-20230620171627773](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230620171627773.png)

根据提示说这个动态包含已通过认证的用户的组的权限是通过复习继承过来的，而这个文件的父系就是磁盘D，此时我们就需要将这个文件的继承关系拿掉，让他不能继承这个权限。点击 禁用继承，选择显示权限。

![image-20230620172231358](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230620172231358.png)

这个显示权限是什么意思呢，说白了就是将父系的权限复制过来，完全成为自己的权限，也就是说，这种情况就不再是继承来的权限了，而是该文件本身具有的权限，选择之后就可以删除了，这样我们就可以使得只有张三有访问的权限，但是张三不能修改，除过管理员，其他的用户的不能访问

## 三、文件夹权限

1.设置文件夹权限

- 列出文件夹
- 创建文件夹
- 创建文件
- 删除
- 删除子文件夹和文件

主要就是对文件夹的属性操作差不多，类似于对文件的属性设置

## 四、权限分类

- 完全控制

![image-20230620224732658](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230620224732658.png)

- 修改

![image-20230620224928573](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230620224928573.png)

- 读取和执行

![image-20230620225101812](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230620225101812.png)

- 读取

![image-20230620225221647](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230620225221647.png)

- 写入

![image-20230620225316448](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230620225316448.png)

- 特别权限

![image-20230620225339447](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230620225339447.png)

