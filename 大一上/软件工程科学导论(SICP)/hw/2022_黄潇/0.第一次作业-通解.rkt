#lang sicp
;实现函数(sum-factor n),计算n的所有因子(d)的和。
;例如,(sum-factor 6)的值为12,因为1、2、3、6是6的所有因子,且1+2+3+6=12

(define(sum-factor n);外部包装过程
 
   (define (sum term i next n)  ;内部定义迭代过程
    (if( > i n )
       0
       (+ (term i) (sum term (next i) next n))))

  (define (term i);定义为内部过程可以使用参数n
    (if(= (remainder n i) 0)
       i
       0))
  
  (define (next i)( + i 1))

  (sum term 1 next n))   ;调用迭代过程sum
       
(sum-factor 6);执行(调用)过程 sum-factor
