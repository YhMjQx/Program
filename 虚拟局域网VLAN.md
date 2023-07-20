

# 虚拟局域网VLAN

主要应用在交换机上

一台交换机默认情况下连接一个广播域，因为默认情况下交换机所有接口都属于同一个VLAN的，默认VLAN1，所以是在同一个广播域中

## 1.目的

- 划分广播域，不同广播域是不能进行通信的，如果想要进行通信，这是需要借助路由
- 增强网络的安全性
- 简化了网络的管理

## 2.VLAN的种类

- 静态VLAN
  - 基于端口划分，需要管理员去配置，创建vlan并将接口加入到vlan
- 动态VLAN
  - 基于MAC地址自动将同一类型的MAC地址加入到同一VLAN

## 3.静态VLAN

- VLAN的范围（思科设备）如果是华为设备，会有所差异
  - 总计4096个VLAN    0~4095
  - 0,4095保留
  - 以太网vlan  2~1001
  - 扩展以太网vlan     1025~4094

4.配置静态VLAN

- 创建VLAN（全局模式下）

```swift
#在全局模式创建
Switch(config)#vlan 2
Switch(config)#vlan 3

#在vlan数据库中创建
Switch#vlan database 
Switch(vlan)#vlan 10
```



![image-20230720205348406](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230720205348406.png)

- 将接口加入VLAN

  - 需要去指定接口的模式

    ```swift
    Switch#conf t
    Switch(config)#int f0/10
    Switch(config-if)#switchport mode access   
    #这种access模式一般是用来链接客户机的
    ```

    

    - 这是加入单个接口

    ```swift
    Switch#conf t
    Switch(config)#int f0/10
    Switch(config-if)#switchport mode access   
    #这种access模式一般是用来链接客户机的
    
    Switch(config-if)#switchport access vlan 2
    #这条命令将f/10这个接口计入vlan2
    ```

    

    - 这是加入多个接口范围

    ```swift
    Switch#conf t
    Switch(config)#int range f0/20-24
    Switch(config-if-range)#switchport mode access
    #上面是设置模式
    
    Switch(config-if-range)#switchport access vlan 3
    #这条命令才是将接口加入vlan3
    ```

    

- 其他配置命令

  - 查看vlan细节

  ```swift
  Switch#show vlan brief 
  ```

  - 查看特定vlan（例如查看vlan2）

  ```swift
  Switch#show vlan id 2
  ```

  - 删除vlan（例如删除vlan10）

  ```swift
  #在全局模式下删除
  Switch(config)#no vlan 10
  
  #在vlan数据库中删除
  Switch#vlan database 
  Switch(vlan)#no vlan 10
  ```

  **通过在交换机上创建vlan，将不同主机加入到对应vlan后，在同一交换机下，相同vlan区域的主机可以直接通信，不同vlan区域中的主机无法直接通信**

# vlan trunk

**同一vlan跨交换机进行通信 **

![image-20230720214017164](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230720214017164.png)