/*
*
*   - Author: jrius ( vk.com/s.fridom | t.me/dcapybarov ) -
*   - Include: format-string
*   - Модуль разработан на версии компилятора 3.10.8 -
*
*   - Модуль предоставляет следующие функции:
*       
*       * TruncateSymbol (string[], symbol[], bool:compare = false)
*           - string - Данные которые нужно с которых нужно будет удалить, также данные string будут изменены и вернуты в переменную где хранилось строка до изменений [!] Обязательный аргумент
*           - symbol - Какой символ будет удален [!] Обязательный аргумент
*           - compare - Включает проверку на регистр символа [!] Необязательный аргумент (false отключить / true включить проверку)
*
*       * TruncateString (string[], max_len, size = sizeof(string))
*         - string - Данные которые нужно разделить, также после выполнение функции все данные которые были в переменой будут изменены на новые. [!] Обязательный аргумент
*         - max_len - Максимальное количество символов [!] Обязательный аргумент
*         - size - длина строки [-] Необязательный аргумент
*
*/

stock TruncateSymbol(string[], symbol[], bool:compare = false) 
{
    new i = 0, j = 0;
    new symbol_char = symbol[0], bool:keep;
    
    while string[i] != '\0' do
    {
        keep = (compare) 
            ? (string[i] != symbol_char)            
            : (tolower(string[i]) != tolower(symbol_char)); 
        
        if (keep) string[j++] = string[i];

        i++;
    }
    string[j] = '\0'; 
}

stock TruncateString(string[], max_len, size = sizeof(string))
{
    if (max_len <= 0 || max_len >= size) 
    {
        printf("[TruncateString] Error! %s", max_len <= 0 ? "max_len is null" : "max_len > size");
        return;  
    }

    new len = strlen(string);

    if (len >= max_len)
    {
        string[max_len] = '\0';
    }
}


stock OnGameModeInit_String()
{
    // Примеры
    new buffer[128];

    buffer = "Привет,как дела?";

    TruncateString(buffer, 7);  // Обрежет до 6 символов
    print(buffer); // вывело - Привет,

    buffer = "Helloworld";

    TruncateString(buffer, 5);  // Обрежет до 5 символов
    print(buffer); // вывело - Hello

    buffer = "Hello;World";

    TruncateSymbol(buffer, ";"); 
    print(buffer); // вывело HelloWorld

    buffer = "Привет форум!";

    TruncateSymbol(buffer, "п", true); 
    print(buffer);
    /*
        [!] Удалит ТОЛЬКО строчную "п":
        - Было: "Привет форум!"
        - Останется: "Привет форум!" 
        (ничего не удалилось, потому что нет строчной "п")
    */

    buffer = "Привет форум!";

    TruncateSymbol(buffer, "п"); 
    print(buffer); 
    /*
        [!] Удалит ТОЛЬКО заглавную "П":
        - Было: "Привет форум!"
        - Стало: "ривет форум!"
        (т.к проверка на регистр отключена)
    */
}