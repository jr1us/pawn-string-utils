/*
*
*   - Author: jrius ( vk.com/s.fridom | t.me/dcapybarov ) -
*   - Include: format-string
*   - ������ ���������� �� ������ ����������� 3.10.8 -
*
*   - ������ ������������� ��������� �������:
*       
*       * TruncateSymbol (string[], symbol[], bool:compare = false)
*           - string - ������ ������� ����� � ������� ����� ����� �������, ����� ������ string ����� �������� � ������� � ���������� ��� ��������� ������ �� ��������� [!] ������������ ��������
*           - symbol - ����� ������ ����� ������ [!] ������������ ��������
*           - compare - �������� �������� �� ������� ������� [!] �������������� �������� (false ��������� / true �������� ��������)
*
*       * TruncateString (string[], max_len, size = sizeof(string))
*         - string - ������ ������� ����� ���������, ����� ����� ���������� ������� ��� ������ ������� ���� � ��������� ����� �������� �� �����. [!] ������������ ��������
*         - max_len - ������������ ���������� �������� [!] ������������ ��������
*         - size - ����� ������ [-] �������������� ��������
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
    // �������
    new buffer[128];

    buffer = "������,��� ����?";

    TruncateString(buffer, 7);  // ������� �� 6 ��������
    print(buffer); // ������ - ������,

    buffer = "Helloworld";

    TruncateString(buffer, 5);  // ������� �� 5 ��������
    print(buffer); // ������ - Hello

    buffer = "Hello;World";

    TruncateSymbol(buffer, ";"); 
    print(buffer); // ������ HelloWorld

    buffer = "������ �����!";

    TruncateSymbol(buffer, "�", true); 
    print(buffer);
    /*
        [!] ������ ������ �������� "�":
        - ����: "������ �����!"
        - ���������: "������ �����!" 
        (������ �� ���������, ������ ��� ��� �������� "�")
    */

    buffer = "������ �����!";

    TruncateSymbol(buffer, "�"); 
    print(buffer); 
    /*
        [!] ������ ������ ��������� "�":
        - ����: "������ �����!"
        - �����: "����� �����!"
        (�.� �������� �� ������� ���������)
    */
}