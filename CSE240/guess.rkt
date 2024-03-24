(#%require (lib "27.ss" "srfi"))

(display "Guess a number from 1 to 100:\nEnter guess ")
(let loop ((gin (read))
           (gu 1)
           (rin (random-integer 100)))
  (cond
    ((> rin gin)
     (display "Higher...Enter guess ")
     (loop (read) (+ 1 gu) rin))
    ((< rin gin)
     (display "Lower...Enter guess ")``
     (loop (read) (+ 1 gu) rin))
    (else
     (+ 1 gu)
     (display "Correct! ")
     (display gu)
     (display " guesses... Please enter your name: ")
     (let ((name (read)))
           (display "Good game, ")
           (display name))
     )`
    )
  )