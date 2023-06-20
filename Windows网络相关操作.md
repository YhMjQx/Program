

# 网络相关操作

## 1.TCP/IP参数 

- IP地址

  -  标识网络中的某一台主机（要想上网就必须要有IP地址）

- 子网掩码

  - 用于标识你的IP地址所处的网络的范围，子网掩码越大，网络范围越小

- 默认网关

  - 用于标识与主机直连的路由器的IP地址

- DNS服务器

  - 用于域名解析（例如用主机访问百度www.baidu.com的时候，是主机与百度的服务器交互，实际上是两个IP地址在进行交互，但我们访问的却是域名，此时我们就要通过DNS将IP地址解出来，然后才知道百度的IP地址是多少，要想访问域名，就必须得有DNS）

  

  ![image-20230618224150329](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230618224150329.png)

  这是我使用命令配置之前的TCP/IP参数

  ```powershell
  #静态配置IP地址，子网掩码，默认网关
  C:\>netsh interface ip set address "Ethernet0" static 192.168.100.100 255.255.255.0 192.168.100.254
  ```

  ```powershell
  #自动获取TCP/IP参数
  C:\>netsh interface ip set address "Ethernet0" dhcp
  ```

  - interface - 接口
  - ip - 这里正常的是ipv4，但是默认的ip就是ipv4，所以就直接用ip来代替ipv4就好了
  - set address - 设置地址，引号内部是接口的名称，这个名称在这里就是Ethernet0，就类似于物理机的WLAN，注意区分大小写
  - static - 表示静态配置
  - IP地址 - 192.168.100.100
  - 子网掩码 - 255.255.255.0 - 确定网络的范围（一般由255构成）
  - 网关 - 192.168.100.254

  ![image-20230618224716212](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230618224716212.png)

这是我使用命令配置之后的TCP/IP参数

![image-20230618234327877](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230618234327877.png)

这是我自动获取的TCP/IP参数

**既然DNS也属于TCP/IP参数，那么我们也是可以通过命令来设置DNS的**

```powershell
#静态配置DNS服务器
C:\>netsh interface ip set dnsserver "Ethernet0" static 12.12.12.12
```

在这里我们就成功配置了DNS服务器

![image-20230619152109828](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230619152109828.png)

但是我们会发现这只是首选DNS服务器，下面还有一个备用DNS服务器，那么备用DNS服务器该如何设置呢？

```powershell
#添加备用DNS服务器
C:\>netsh interface ip add dnsserver "Ethernet0" 222.66.66.66 index=2
#index=2 原因是因为我们填的DNS服务器的框是第二个框，因此索引位置是二,表示备用DNS
```

![image-20230619153040799](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230619153040799.png)

这个界面可以使用 `ipconfig /all`查看更为全面的TCP/IP参数

```powershell
#自动获取DNS服务器
C:\>netsh interface ip set dnsserver "Ethernet0" dhcp
```

## 2.查看TCP/IP参数

**使用 `ipconfig`命令**

![image-20230619154303861](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230619154303861.png)

```powershell
ipconfig 	#查看所有网卡的TCP/IP参数（IP地址，子网掩码，默认网关）
ipconfig /all 	#查看所有网卡TCP/IP参数（IP地址，子网掩码，默认网关，mac地址，dhcp地址，dns地址，主机名）
ipconfig /release 	#释放TCP/IP参数
ipconfig /renew 	#重新获取TCP/IP参数
ipconfig /flushdns 	#刷新DNS缓存
```

## 3.ping命令

ping命令跳过传输层，直接使用网络层的ICMP回送请求和回答报文

**用于测试TCP/IP配置是否正确**

```powershell
ping -n 10 	#默认发送的报文的个数为4，该命令指定发送10个报文
ping -l 10000 	#默认发送的报文的大小为32字节，该命令指定发送的报文的大小为10000字节
ping -t 	#一直不停的ping， Ping 指定的主机，直到停止。若要查看统计信息并继续操作，Ctrl+Break；若要停止，请键入 Ctrl+C。
ping -a 	#将IP地址解析为主机名
```

## 4.路由跟踪tracert

**功能：追踪本台主机到达目标点中间会有多少个跃点，说白了就是中间有多少个路由器**

```powershell
C:\>tracert 39.156.66.14 	#本主机访问百度所经过的路线
```

## 5.路由route

用来操作网络路由表

![image-20230619165112154](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230619165112154.png)

这就是这台虚拟机（Windows Server 2016-1）的网络路由表

`0.0.0.0`表示任意网络的网络目标，反正不管访问什么网络都是要经过自己的网关出去的

```powershell
#打印路由表
route -4 print或者routeprint -4

#添加路由条目(112.53.42.52 - 目标地址或网络，/32 - 子网掩码)(112.53.42.0 - 目标地址或网络，/24 - 子网掩码)(192.168.33.1 - 网关地址)
route add 112.53.42.52/32 192.168.33.1

#删除路由条目(112.53.42.52 - 网络目标)
route delete 112.53.42.52
```

## 6.netstat

显示统计TCP/IP链接，显示协议统计信息和当前 TCP/IP 网络连接。

![image-20230619171430400](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20230619171430400.png)

```powershell
#查看所有的TCP/IP链接，包括进程，以数字形式显示
C:\>netstat -anop tcp

#查看路由表 等同于 route print
C:\>netstat -r
```

