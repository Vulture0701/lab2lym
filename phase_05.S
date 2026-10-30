
./bomb:     file format elf64-x86-64


Disassembly of section .init:

Disassembly of section .plt:

Disassembly of section .plt.sec:

Disassembly of section .text:

0000000000402480 <phase_05>:
  402480:	endbr64
  402484:	push   %rbp
  402485:	mov    %rsp,%rbp
  402488:	push   %r12
  40248a:	mov    %rsi,%r12
  40248d:	mov    $0x2,%esi
  402492:	push   %rbx
  402493:	mov    %rdi,%rbx
  402496:	sub    $0x10,%rsp
  40249a:	call   402c80 <valid_u32_fields>
  40249f:	test   %al,%al
  4024a1:	jne    4024b0 <phase_05+0x30>
  4024a3:	xor    %eax,%eax
  4024a5:	add    $0x10,%rsp
  4024a9:	pop    %rbx
  4024aa:	pop    %r12
  4024ac:	pop    %rbp
  4024ad:	ret
  4024ae:	xchg   %ax,%ax
  4024b0:	xor    %eax,%eax
  4024b2:	lea    -0x18(%rbp),%rcx
  4024b6:	lea    -0x1c(%rbp),%rdx
  4024ba:	mov    $0x403186,%esi
  4024bf:	mov    %rbx,%rdi
  4024c2:	call   4011e0 <__isoc99_sscanf@plt>
  4024c7:	cmp    $0x2,%eax
  4024ca:	jne    4024a3 <phase_05+0x23>
  4024cc:	lea    -0x14(%rbp),%rsi
  4024d0:	mov    %r12,%rdi
  4024d3:	call   402410 <p5_traverse>
  4024d8:	mov    %eax,%edx
  4024da:	xor    %eax,%eax
  4024dc:	cmp    %edx,-0x1c(%rbp)
  4024df:	jne    4024a5 <phase_05+0x25>
  4024e1:	mov    -0x14(%rbp),%eax
  4024e4:	cmp    %eax,-0x18(%rbp)
  4024e7:	sete   %al
  4024ea:	jmp    4024a5 <phase_05+0x25>

Disassembly of section .fini:
