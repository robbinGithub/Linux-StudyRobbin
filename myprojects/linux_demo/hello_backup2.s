	.file	"hello.c"
	.section	.rodata
.LC0:
	.string	"%d\n"
.LC1:
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
        #将原rsp赋值给rbp
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
        #rsp-16 （栈生长方向从高到低)
	subq	$16, %rsp
        #将立即数5放入本地变量表(rbp-4)位置
	movl	$5, -4(%rbp)
        #将本地变量表内存数据移动至寄存器eax = 5
	movl	-4(%rbp), %eax
        #将eax中的5传送到变址寄存器  esi = 5
	movl	%eax, %esi
        #将LC0段地址传送到变址寄存器 edi = LCO段地址
	movl	$.LC0, %edi
	movl	$0, %eax                // eax = 0
        #调用库函数printf(内部系统调用)
	call	printf
	movl	$.LC1, %edi
	call	puts
	leave
	.cfi_def_cfa 7, 8
        #返回 mov %rbp %rsp | poqp %rbp 
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-39)"
	.section	.note.GNU-stack,"",@progbits
