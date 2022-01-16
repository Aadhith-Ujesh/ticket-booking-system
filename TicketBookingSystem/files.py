
for i in range(1,401):
    file1 = open("MyFile.txt", "a") 
    print(str(i))
    L = ["private: System::Void checkBox",str(i),"_CheckedChanged_1(System::Object^ sender, System::EventArgs^ e) {\n",
        "if (checkBox",str(i),"->Checked == true)\n",
        "{\n",
        "\tcheckBox",str(i),"->BackColor = Color::FromArgb(0, 255, 255);\n",
        "}\n",
        "else\n",
        "{\n",
        "\tcheckBox",str(i),"->BackColor = Color::FromArgb(255, 255, 255);\n",
        "}\n",
    "}"]
    file1.writelines(L)
file1.close()