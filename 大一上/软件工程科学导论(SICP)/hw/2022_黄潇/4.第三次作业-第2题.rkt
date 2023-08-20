#lang sicp
;实现过程(plus-index items),给定表items作为参数,求值结果是这样一张表,
;其元素数目和items的元素数目相同,并且每个元素 = items中对应元素+下标。
(define (plus-index items)
  (define (plus-iter index iter-items)
    (if(null? iter-items)
       nil
       (cons (+ (car iter-items) index)
             (plus-iter (+ index 1) (cdr iter-items)))))
 (plus-iter 0 items)
  )

(define plus-list (list 1 8 2 12 6 3 4 5))
(plus-index plus-list)