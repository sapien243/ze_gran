#lang sicp
;;; == chapter 01 == ;;;

;; expressions
(+ (* 3 5) (- 10 7) (/ 24 4 2))
;

;; naming
(define pi 3.14159)
;

;; compound procedures
(define (sq x) (* x x))
(define (cb x) (* x x x))
(define (circle_area r)
  (* pi (sq r)))
;

;; conditionals
(define (abs x)           ;(define (abs x)           ;(define (abs x)
  (if (< x 0) (- x) x))   ;  (cond ((< x 0) (- x))   ;  (cond ((> x 0) x)
;|                        ;        (else x)))        ;        ((= x 0) 0)
;|                        ;|                         ;        ((< x 0) (- x))))
(define (plus_abs a b)
  ((if (> b 0) + -) a b))
;| (and () () ())   ;| (or () () ())   ;| (not ())   ;| #t #f
(define (tst_1 x)
  ((if (< x 0) abs sq) x))
;

;; sqrt ~ newton's method
(define (sqrt x)
  (define (good ges)
    (< (abs (- (sq ges) x)) 0.0001))
  (define (impr ges)
    (/ (+ (/ x ges) ges) 2.0))
  (define (iter ges)
    (if (good ges) ges
        (iter (impr ges))))
  (iter 1.0))
;*

;; linear recursive procedures
; factorial process ~ linear recursive
(define (fact_rec n)
  (if (= n 1) 1
      (* n (fact_rec (dec n)))))
; factorial process ~ iterative
(define (fact_itr n)
  (define (iter ans cnt n)
    (if (> cnt n) ans
        (iter (* cnt ans) (inc cnt) n)))
  (iter 1 1 n))
;

;; tree recursive procedures
; fibonacci process ~ tree recursive
(define (fib_rec n)
  (cond ((= n 0) 0)
        ((= n 1) 1)
        (else (+ (fib_rec (- n 1)) (fib_rec (- n 2))))))
; fibonacci process ~ iterative
(define (fib_itr n)
  (define (iter add ans n)
    (if (= n 0) ans
        (iter (+ ans add) add (dec n))))
  (iter 1 0 n))
; counting change/coin change
;*
; ex 1.11 process ~ recursive
(define (f_rec n)
  (if (< n 3) n
      (+ (f_rec(- n 1)) (* 2 (f_rec(- n 2))) (* 3 (f_rec(- n 3))))))
; ex 1.11 process ~ iterative
(define (f_itr n)
  (define (iter ans b c cnt n)
    (if (> cnt n) ans
        (iter (+ ans (* 2 b) (* 3 c)) ans b (inc cnt) n)))
  (if (< n 3) n
      (iter 2 1 0 3 n)))
; sine function (in radians) :ex 1.15
(define (sin ang)
  (define (proc x) (- (* 3 x) (* 4 (cb x))))
  (if (< (abs ang) 0.0001) ang
      (proc (sin (/ ang 3.0)))))
;

;==
(define (divs? a b) (= (remainder a b) 0))
(define (even? n) (= (remainder n 2) 0))
;==

;; exponentiation
; successive squaring ~ recursive
(define (xpn_rec b n)
  (cond ((= n 0) 1)
        ((even? n)(sq (xpn_rec b (/ n 2))))
        (else (* b (xpn_rec b (- n 1))))))
; successive squaring ~ iterative
(define (xpn_itr b n)
  (define (iter ans m cnt)
    (if (= cnt m) ans
        (iter (sq ans) m (* cnt 2))))
  (cond ((= n 0) 1)
        ((= n 1) b)
        ((even? n) (iter b n 1))
        (else (* b (iter b (- n 1) 1)))))
; fib_adv : pg 89
;*

;; gcd of 2 numbers {euclid's algorithm}
(define (gcd a b)
  (if (= b 0) a
      (gcd b (remainder a b))))
;

;; testing for primality
; divisor search
(define (s_div n)
  (define (next div)
    (if (= div 2) (inc div) (+ div 2)))
  (define (f_div n div)
    (cond ((> (sq div) n) n)
          ((divs? n div) div)
          (else (f_div n (next div)))))
  (f_div n 2))
; is prime ~ divisor search
(define (prime? n) (= n (s_div n)))
; ex 1.22
(define (t_prime? n)
  (define (show n t)
    (display (list n " :: " t "ms"))(newline))
  (define (test n start)
    (if (prime? n) (show n (- (runtime) start))))
  (test n (runtime)))
; search 3 smallest primes from x
;(define (p_search x)
;  (define (iter x cnt)
;    (t_prime? x)
;    (if (not (= cnt 3)) (iter (inc x) cnt)))
;  (iter x 0))*

;; higher order procedures
; sum of integers
(define (sum_int a b)
  (if (> a b) 0
      (+ a (sum_int (inc a) b))))
; sum of cubes
(define (sum_cbs a b)
  (if (> a b) 0
      (+ (cb a) (sum_cbs (inc a) b))))
; sum of sequence converging to pi/8
(define (pi_sum a b)
  (if (> a b) 0
      (+ (/ 1.0 (* a (+ a 2))) (pi_sum (+ a 4) b))))
;; the sum~ template
(define (sum~ opr nxt a b)
  (if (> a b) 0
      (+ (opr a) (sum~ opr nxt (nxt a) b))))
; sum~ ints
(define (sum~int a b)
  (define (id a) a)
  (sum~ id inc a b))
; sum~ cbs
(define (sum~cbs a b)
  (sum~ cb inc a b))
; pi sum~
(define (pi~sum a b)
  (define (opr a) (/ 1.0 (* a (+ a 2))))
  (define (nxt a) (+ a 4))
  (sum~ opr nxt a b))
; integral approximation
(define (integral~ fx ll ul dx)
  (define (nxt a) (+ a dx))
  (* (sum~ fx nxt (+ ll (/ dx 2.0)) ul) dx))
; integral~ simpson's rule

;
;
;;;
;;;