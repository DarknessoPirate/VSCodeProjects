from datetime import date

with open("raport.html", "w") as raport:
    raport.write("<html>\n"
                 "<head>\n"
                 "<style type=\"text/css\">\n"
                 "h1 {\n"
                 "margin-bottom: 1px;\n"
                 "}\n"
                 "</style>\n"
                 "<title>Raport</title>\n"
                 "</head>\n"
                 "<h1>Raport z aplikacji kalendarz</h1>\n"
                 f"<p><font size=\"4\"> Wygenerowano w dniu: {date.today()}  </font></p>\n"
                 "<div style=\"white-space: pre\">\n")
    with open("data.txt", "r") as data:
        for line in data:
            if line[0] == "#":
                raport.write('\n')
                raport.write(line.removeprefix("#").strip())
                raport.write('\n')
            else:
                raport.write(line)
    raport.write("</div>\n"
                 "</body>\n"
                 "</html>\n")