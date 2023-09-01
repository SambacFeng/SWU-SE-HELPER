#lang sicp
;第一题:
;实现函数(sum-factor n),计算n的所有因子(d)的和。

(define(sum-factor n)
  
  (define (factor? n i)    ;内部定义过程，判断i是否n的因子，返回真假值
    (= (remainder n i) 0))
  
  (define (sum-iter n i)  ;内部定义迭代过程
    (cond(( > i n ) 0)  ;i>n,结束递归，返回0，即最后加上0
         ((factor? n i) (+ i (sum-iter n (+ i 1))))  ;i是因子，迭代值+i
         (else (sum-iter n (+ i 1)))))

  (sum-iter n 1))   ;定义过程(sum-factor n)的过程体——调用迭代过程sum-iter
       
;执行（调用）过程 sum-factor:
(sum-factor 6)
