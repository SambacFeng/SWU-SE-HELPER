#lang sicp
(define (plus-index items)
  (define (plus-index-in items sub)
    (if (null? items)
        nil
        (cons (+ sub (car items)) (plus-index-in (cdr items) (+ 1 sub)))))
  (plus-index-in items 0))