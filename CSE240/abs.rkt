(define sign
  (lambda (x)
    (cond
      ((> x 0) x)
      ((= x 0) 0)
      (else (* x -1)))))

(sign 0)
