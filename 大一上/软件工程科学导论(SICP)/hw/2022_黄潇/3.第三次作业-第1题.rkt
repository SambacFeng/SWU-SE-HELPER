#lang sicp
;递归拆表——返回表中元素的数目。
;拆表的含义:每次只保留(cdr items),即拆第一个元素(car items)后当前余下的items表,
;重复此过程至递归结束。

(define (count-list items) ;拆表-累计表中元素个数（表长度）
  (if(null? items)
     0
     (+ 1 (count-list (cdr items)))));拆去(car items),元素个数+1

(define (last-part n input-items);构造新表，保留原表中最后n个元素
  ;递归拆表,拆去前0~length-n-1个元素，length为原表中元素数目
  (define (getlist-rec items index length)
    (cond((>= n length);当n大于表的长度时,last-part的求值结果为items
          items)
         ((< index (- length n));下标index从0开始
          (getlist-rec (cdr items) (+ index 1) length ));递归拆表，下标+1
         (else
          items)))
  (getlist-rec input-items 0 (count-list input-items)) )
                             
(last-part 3 (list 2 8 1 10 5 20))