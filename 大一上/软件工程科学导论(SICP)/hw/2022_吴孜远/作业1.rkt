#lang sicp
(define (enumerate-interval low high)
  (if (> low high)
    nil
    (cons low (enumerate-interval ( + low 1) high))))

(define (filter predicate sequence)
  (cond ((null? sequence) nil)
        ((predicate (car sequence))
         (cons (car sequence)
               (filter predicate (cdr sequence))))
    (else (filter predicate (cdr sequence)))))

(define (accumulate op initial sequence)
  (if (null? sequence)
      initial
      (op (car sequence)
          (accumulate op initial (cdr sequence)))))

(define (sum-factor n)
  (define (factor? x)
     (= (remainder n x) 0))
  (accumulate + 0
    (filter factor? (enumerate-interval 1 n))))
