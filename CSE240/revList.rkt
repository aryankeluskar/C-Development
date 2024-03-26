(define reverse2
  (lambda (oldlst newlst)
    (cond
      ((null? oldlst) newlst)
      (else (reverse2 (cdr oldlst) (cons (car oldlst) newlst))))))

(define L '(5 8 6 4 2 5 6 8 9 7 5 2 6))

(reverse2 L '())
