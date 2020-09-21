# 欢迎大家使用 ScreenAdaptation

1.拖入文件 LonnieScreen

2.导入头文件

 #import "LonnieScreen.h" 

3.使用方式

```objective-c
- ( void )viewDidLoad {
  [super  viewDidLoad];
  
  UIView * view=[[UIView alloc]initWithFrame:CGRectMake(0, 0, tRealLength(50), tRealLength(50))];
  NSLog(@"真实长度：%f",tRealLength(50));
  view.backgroundColor=[UIColor redColor];
  [self .view addSubview:view];

  NSLog(@"当前设备");
   switch  (tCurrentType()) {

​     case AdapterPhoneType_iPhone3GS_4_4S:

​      NSLog(@"TXAdapterPhoneType_iPhone3GS_4_4S");

​       break ;

​     case  AdapterPhoneType_iPhone5_5C_5S_5SE:

​      NSLog(@"TXAdapterPhoneType_iPhone5_5C_5S_5SE");

​       break ;

​     case  AdapterPhoneType_iPhone6_6S_7_8:

​      NSLog(@"TXAdapterPhoneType_iPhone6_6S_7_8");

​       break ;

​     case  AdapterPhoneType_iPhone6Plus_6SPlus_7Plus_8Plus:

​      NSLog(@"TXAdapterPhoneType_iPhone6Plus_6SPlus_7Plus_8Plus");

​       break ;

​     case  AdapterPhoneType_iPhoneX_Xs_11Pro:

​      NSLog(@"TXAdapterPhoneType_iPhoneX_Xs_11Pro");

​       break ;

​     case  AdapterPhoneType_iPhoneXsMax_XR_11_11ProMax:

​      NSLog(@"TXAdapterPhoneType_iPhoneXsMax_XR_11_11ProMax");

​     case  AdapterPhoneTypeOther:

​       break ;

​     default :

​       break ;

  }

}
```

