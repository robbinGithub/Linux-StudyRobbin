	.file	"hello.c"
	.section	.rodata
.LC0:
	.string	"hello world!"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
        #栈基址寄存器rbp入栈
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
        #rbp = rsp
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
        #将LC0段基地址传入edi寄储器
	movl	$.LC0, %edi
	call	puts
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-39)"
	.section	.note.GNU-stack,"",@progbits
