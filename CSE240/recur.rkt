(define sigma
  (lambda (n)
         (if (= n 1)
             1
             (+ n (sigma (- n 1))))))

(sigma 10)

(define power
  (lambda (x n)
    (if (= n 0)
        1
        (* x (power x (- n 1))))))

(power 3 5)