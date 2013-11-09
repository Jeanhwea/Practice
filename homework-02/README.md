homework-02
===========

现代程序设计第二次作业

代码说明：
-----------

### 输入文件样例
		3,
		6,
		5,6,-3,8,-9,2
		1,-12,20,0,-3,-5
		-9,-7,-3,6,7,-1

### 输入文件内容说明
> 
第一行是行数后紧接着一个逗号
> 
第二行是列数后紧接着一个逗号
> 
第三行到结束是所有的元素，每行中的元素以
> 
逗号分割，其间没有空格

执行代码：
-----------
		$ make                   # 编译代码
		$ ./run /v /h <filename> # 执行代码
> 
最后生成的数字为输出结果。

生成随机的测试脚本：
-----------
		$ bash random.sh 3 4 > output.txt
		# 生成3行4列名字为output.txt的输入文件

其它说明：
-----------
> 
工程里有几个测试数据文件
> 
命名为500m500这是一个规模为500乘以500的测试
数据

测试代码覆盖率：
-----------

### gcov 简单查看代码覆盖率
> 
对于简单文本的代码覆盖率，可以用 gcov 工具获得。
> 
方法是
> 
编译时添加 -fprofile-arcs -ftest-coverage 选项
> 
链接时添加 -fprofile-arcs -ftest-coverage -lgcov 选项
> 
查看的命令如下：
> 

		$ gcov main.c # 生成文本 main.c.gcov
		$ vim main.c.gcov # 直接用 vim 读文本

### lcov 生成 html 文件
> 
少量文件使用 gcov 查看就可以了，对于工程建议使用 lcov
> 
来生成 html 文本。记得先安装 lcov
> 

		$ apt-get install lcov # for ubuntu user

> 
利用 lcov 生成的 html 结果非常好看，步骤如下：
> 
		$ lcov -c -d ./ -o app.info # 生成中间文件
		$ genhtml app.info -o result # 生成html目录
> 
打开 result 目录就可看见代码覆盖率信息


