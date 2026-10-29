
./bomb:     file format elf64-x86-64


Disassembly of section .init:

Disassembly of section .plt:

Disassembly of section .plt.sec:

Disassembly of section .text:

0000000000402320 <p4_walk>:
  402320:	endbr64
  402324:	mov    %edi,%eax
  402326:	mov    %edx,%edi
  402328:	sub    %esi,%edi
  40232a:	shr    $1,%edi
  40232c:	add    %esi,%edi
  40232e:	cmp    %eax,%edi
  402330:	je     402380 <p4_walk+0x60>
  402332:	push   %rbp
  402333:	mov    %rsp,%rbp
  402336:	push   %rbx
  402337:	lea    (%rdi,%rcx,1),%ebx
  40233a:	sub    $0x8,%rsp
  40233e:	cmp    %edi,%eax
  402340:	jb     402360 <p4_walk+0x40>
  402342:	lea    0x1(%rdi),%esi
  402345:	mov    %eax,%edi
  402347:	call   402320 <p4_walk>
  40234c:	lea    (%rax,%rax,4),%eax
  40234f:	xor    %ebx,%eax
  402351:	mov    -0x8(%rbp),%rbx
  402355:	leave
  402356:	xor    $0x9,%eax
  402359:	ret
  40235a:	nopw   0x0(%rax,%rax,1)
  402360:	lea    -0x1(%rdi),%edx
  402363:	mov    %eax,%edi
  402365:	call   402320 <p4_walk>
  40236a:	lea    (%rax,%rax,4),%eax
  40236d:	xor    %ebx,%eax
  40236f:	mov    -0x8(%rbp),%rbx
  402373:	leave
  402374:	xor    $0xb,%eax
  402377:	ret
  402378:	nopl   0x0(%rax,%rax,1)
  402380:	lea    0x3a(%rdi),%eax
  402383:	xor    %ecx,%eax
  402385:	ret

Disassembly of section .fini:
