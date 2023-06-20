# Windows用户管理

## 一、用户账户

### 1.什么是用户账户

- 不同的用户身份有不同的权限

- 每个用户包含了一个名称和一个密码

- 每个用户账户具有唯一的安全标识符

  ```
  #查看系统中的用户
  net user
  ```

- 安全标识符（SID）

```
#查看当前用户的SID
whoami /user
```

![image-20230619174655828](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230619174655828.png)

管理员的SID是默认为500，一般用户是1000开始

使用注册表命令查看其他用户的SID，用regedit打开注册表

```
#这是注册表路径
HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows NT\CurrentVersion\ProfileList
```

```powershell
#用于查看所有用户的SID
C:\>wmic useraccount get name,sid
```

![image-20230619183847311](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230619183847311.png)

### 2.进行用户管理

- 创建用户

  - 用户名：系统的显示名

  - 全名：用户登录时的显示名

  - 密码：Windows服务器默认需要符合复杂性要求

  - 账户已锁定：如果开启了账户锁定阈值，那么输错密码多次后将被锁定

    ```powershell
    #创建用户不指定密码
    net user zhangsan /add
    ```

    

    ```powershell
    #创建用户明文指定密码(zhangsan - 用户名，p-0p-0p-0 - 密码)
    net user zhangsan p-0p-0p-0 /add
    ```

    但是如果我的电脑被监听了，这种明文设置密码的方式很危险，那么如何使用密文的方式设置密码呢？？？

    ![image-20230619204928261](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230619204928261.png)

    ```powershell
    #创建用户密文指定密码
    net uiser lisi /add *
    ```

    这里的 * 是密码的占位符，这样就可以以密文的方式设置密码

    

  

- 删除用户

  ```powershell
  #删除用户
  net user lisi /del
  ```

- 修改用户密码

  ```powershell
  #明文修改密码
  net user lisi p-0p-0p-0
  ```

  ```powershell
  #密文修改密码
  net user lisi *
  ```

- 隐藏用户

```powershell
net user lisi$ /add *
```

这种隐藏用户直接使用 `net user`是看不见的，但是在系统或者 `wmic useraccount get name,sid`中是可以看得见的

## 二：Windows的内置用户账户

1.与使用者关联的

- 管理员administrator：在使用中具有最高的权限，如果没有其他管理员的情况
- 普通用户：具有一般的读取权限，权限较低
- 来宾用户Guest：一般是提供给方可使用，在使用者关联中权限最低，默认是禁用

2.与Windows组件关联的

- system 本地系统，拥有最高权限
- local service 本地服务，他的权限相对于普通用户组users会低一点
- network service 网络服务，他的权限和普通用户组users一样