;; int xor(long, long);
global xor:function
xor:
	mov rax, rdi
	xor rax, rsi
	ret

global or:function
or:
	mov rax, rdi
	or rax, rsi
	ret

global sum:function
sum:
;;rax refers to res
;; rcx refers to i
;;rsi refers to len
;;rdi refers to arr
	xor rax, rax
	xor rcx, rcx

.sum_loop:
	cmp rsi, rcx
	jz .exit_sum
	add rax, [rdi + 8*rcx]
	add rcx, 1
	jmp .sum_loop

.exit_sum:
	ret

