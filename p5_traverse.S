
./bomb:     file format elf64-x86-64


Disassembly of section .init:

Disassembly of section .plt:

Disassembly of section .plt.sec:

Disassembly of section .text:

0000000000402410 <p5_traverse>:
  402410:	endbr64
  402414:	mov    %rdi,%rax
  402417:	mov    %rdi,%rcx
  40241a:	mov    %rsi,%r8
  40241d:	and    $0x7,%eax
  402420:	shr    $0x3,%rcx
  402424:	mov    0x405b60(,%rax,8),%rdx
  40242c:	mov    %rdi,%rax
  40242f:	shr    $0x20,%rdi
  402433:	shr    $0x6,%rax
  402437:	xor    %edi,%eax
  402439:	mov    0x8(%rdx),%esi
  40243c:	mov    %ecx,%edi
  40243e:	xor    $0xebb3,%eax
  402443:	add    0xc(%rdx),%eax
  402446:	lea    (%rax,%rax,4),%eax
  402449:	mov    %esi,(%r8)
  40244c:	xor    %esi,%eax
  40244e:	and    $0x3,%edi
  402451:	je     402470 <p5_traverse+0x60>
  402453:	mov    $0x1,%ecx
  402458:	mov    (%rdx),%rdx
  40245b:	add    $0x1,%ecx
  40245e:	mov    0x8(%rdx),%esi
  402461:	add    0xc(%rdx),%eax
  402464:	lea    (%rax,%rax,4),%eax
  402467:	mov    %esi,(%r8)
  40246a:	xor    %esi,%eax
  40246c:	cmp    %ecx,%edi
  40246e:	jae    402458 <p5_traverse+0x48>
  402470:	ret

Disassembly of section .fini:
