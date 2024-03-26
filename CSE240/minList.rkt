(#%require racket/trace)

(define min-list
  (lambda (lst)
    (cond
      ((null? (cdr lst)) (car lst))
      (else (min (car lst) (min-list (cdr lst)))))))

(define L '(5 8 6 4 2 5 6 8 9 7 5 2 6))
(trace min-list)
(min-list L)