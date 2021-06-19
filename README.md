<script src="https://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS-MML_HTMLorMML" type="text/javascript"></script>

<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    tex2jax: {
      inlineMath: [ ['$','$'], ["\\(","\\)"] ],
      processEscapes: true
    }
  });
</script>

# PDL_ILP 代码说明
LP.cpp 为单纯形法求实数最优解
branch.cpp 为分支限界求整数最优解
divplane.cpp 为割平面法求整数最优解
branch_approximate.cpp 为分支限界求近似比为10/9的整数可行解
MonteCarlo_approximate.cpp 为修改版蒙特卡洛求整数可行解

输入格式：
第一行n,m表示变量$x_1,x_2,...,x_n$和约束的个数
第二行n个数$c_1,c_2,...,c_n$表示最大化函数$c_1*x_1+c_2*x_2+....+c_n*x_n$
接下来m行，每行n+1个数$a_1,a_2,....,a_n,b_j$,表示约束$a_1*x_1+a_2*x_2+....+a_n*x_n<=b_j$

输出格式：
输出"Infeasible"表示无解
输出"Unbounded"表示最优解无界
否则输出两行，第一行一个数为求得最优化函数值
第二行为n个数，表示n个变量的取值

汉字编码用GB2312打开
