LP.cpp 为单纯形法求实数最优解
branch.cpp 为分支限界求整数最优解
divplane.cpp 为割平面法求整数最优解
branch_approximate.cpp 为分支限界求近似比为10/9的整数可行解
MonteCarlo_approximate.cpp 为修改版蒙特卡洛求整数可行解

输入格式：
第一行n，m表示变量x1,x2...xn和约束的个数
第二行n个数c1,c2....cn表示最大化函数c1*x1+c2*x2....+cn*xn
接下来m行，每行n+1个数a1,a2....an,bj，表示约束a1*x1+a2*x2+....+an*xn<=bj

输出格式：
输出"Infeasible"表示无解
输出"Unbounded"表示最优解无界
否则输出两行，第一行一个数为求得最优化函数值
第二行为n个数，表示n个变量的取值

汉字编码用GB2312打开