#lang sicp

(define (square x)
  (* x x))

(define (compose f g)
  (lambda (x) (f (g x))))


(define (repeated h n)
  (if (= n 1)
      h
      (compose h (repeated h (- n 1)))))