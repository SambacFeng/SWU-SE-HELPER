#lang sicp
(define (compose f g);定义f(g(x))组合（嵌套）调用,g为当前的过程嵌套调用
  (lambda(x)
    (f (g x))))
  
(define (repeated f n);高阶过程repeated以f过程为参数，以匿名过程为执行结果

  (define (f-rec func n) ;递归生成过程的嵌套-重复嵌套调用f过程n次
    (if(= 1 n)
       func ;返回最后的组合（嵌套）调用过程
       (f-rec (compose f func) (- n 1))));递归生成过程的嵌套,func为当前过程嵌套
  
  (lambda(x);定义repeated过程体
    ((f-rec f n) x)));代入参数x,返回n次嵌套调用f过程的执行结果

(define (square x)(* x x))

;调用(repeated square n),返回组合过程,代入参数x=5,求得最后结果
((repeated square 1) 5)
((repeated square 2) 5)
((repeated square 3) 5)
((repeated square 4) 5)