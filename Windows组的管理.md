# Windows组的管理

**用户**

1.与人员关联的

- administrator
- guest

2.与组件关联

- system
- local service
- network service

## 一、用户组

1.概念

- 一组用户的集合，组中所有的用户具备所组的权限

2.管理组

```powershell
#创建组
net localgroup 销售部 /add

#删除组
net localgroup 销售部 /add

#将hy这个用户添加进第一组这个族中
net localgroup 第一组 hy /add

#将hy这个用户从第一组这个族中删除
net localgroup 第一组 hy /del
```

![image-20230620134231931](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230620134231931.png)

![image-20230620134252504](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230620134252504.png)

## 二：内置组账户

1.需要人为添加

- administrators：管理员组
- guests：来宾用户组
- powerusers：向下兼容的，现在一般没有使用
- users：标准用户组，创建用户后默认处于此组中

2.动态包含成员的组

- interactive：动态包含在本地用户登录的组
- authenticated：动态包含已通过认证的用户
- everyone：所有人，包含guest