# setuid, setgid, seteuid, setegid
* `setuid(uid_t new_uid); // setgid(gid_t new_gid);`
  * Root가 아닌 경우: 사용자의 euid를 new_uid로 바꿈
  * Root: uid, euid, saved-uid를 new_uid로 바꿈
* `setuid(uid_t new_uid); // setgid(gid_t new_gid);`
  * Root가 아닌 경우: 사용자의 euid를new_euid로 바꿈. 단 new_euid는 사용자의 uid또는 saved_uid중 하나이어야 함
  * Root: 사용자의 euid를 new_euid로 바꿈. 어떤 값도 가능
* Program 예
  * case 1
    ```
    1. suid 비트설정     // uid | euid | saved-uid
       프로그램 실행      // 1000|  0   |     0
    2. seteuid(1000);  // 1000| 1000 |     0
    3. seteuid(0);     // 1000|  0   |     0
    ```
  * case 2
    ```
    1. suid 비트설정      // uid | euid | saved-uid
       프로그램 실행       // 1000|  0   |     0
    2. setuid(1000);    // 1000| 1000 |   1000
    3. seteuid(0);      // 1000| 1000 |   1000
    ```
