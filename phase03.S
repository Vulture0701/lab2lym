
./bomb:     file format elf64-x86-64


Disassembly of section .init:

Disassembly of section .plt:

Disassembly of section .plt.sec:

Disassembly of section .text:

00000000004022a0 <phase_03>:
  4022a0:	endbr64
  4022a4:	push   %rbp
  4022a5:	mov    %rsp,%rbp
  4022a8:	push   %r12
  4022aa:	mov    %rsi,%r12
  4022ad:	mov    $0x2,%esi
  4022b2:	push   %rbx
  4022b3:	mov    %rdi,%rbx
  4022b6:	sub    $0x10,%rsp
  4022ba:	call   402c80 <valid_u32_fields>
  4022bf:	test   %al,%al
  4022c1:	jne    4022d0 <phase_03+0x30>
  4022c3:	xor    %eax,%eax
  4022c5:	add    $0x10,%rsp
  4022c9:	pop    %rbx
  4022ca:	pop    %r12
  4022cc:	pop    %rbp
  4022cd:	ret
  4022ce:	xchg   %ax,%ax
  4022d0:	xor    %eax,%eax
  4022d2:	lea    -0x14(%rbp),%rcx
  4022d6:	lea    -0x18(%rbp),%rdx
  4022da:	mov    $0x403186,%esi
  4022df:	mov    %rbx,%rdi
  4022e2:	call   4011e0 <__isoc99_sscanf@plt>
  4022e7:	cmp    $0x2,%eax
  4022ea:	jne    4022c3 <phase_03+0x23>
  4022ec:	mov    %r12d,%edi
  4022ef:	xor    %eax,%eax
  4022f1:	and    $0x7,%edi
  4022f4:	cmp    %edi,-0x18(%rbp)
  4022f7:	jne    4022c5 <phase_03+0x25>
  4022f9:	mov    %r12,%rax
  4022fc:	mov    %r12,%rsi
  4022ff:	shr    $0x3,%rax
  402303:	shr    $0x20,%rsi
  402307:	xor    %eax,%esi
  402309:	call   402240 <p3_dispatch>
  40230e:	cmp    %eax,-0x14(%rbp)
  402311:	sete   %al
  402314:	jmp    4022c5 <phase_03+0x25>

Disassembly of section .fini:
