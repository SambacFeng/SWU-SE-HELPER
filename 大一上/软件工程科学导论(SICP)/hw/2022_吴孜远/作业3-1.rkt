#lang sicp

(define (length seq)
  (if (null? seq)
      0
      (+ 1 (length (cdr seq)))))

(define (last-part n items)
  (define (switch x items)
    (cond ((< x 0) items)
          (else (if (= x 0)
              items
              (switch (- x 1) (cdr items))))))
   (switch (- (length items) n) items))