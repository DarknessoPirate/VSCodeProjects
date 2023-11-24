
capitals = {"USA":'Washington DC', 
            'Poland':'Warsaw',
            'China':'Beijing',
            'Russia':'Moscow'}

#print(capitals['Russia'])
#print(capitals.get("Germany")) #safer method
#print(capitals.keys()) #prints only the keys
#print(capitals.values()) # prints only the values
#print(capitals.items()) # prints both keys and the corresponding values



#capitals.update({'Germany':'Berlin'})
#capitals.update({'USA':'Uganda'})
#print(capitals.get('USA'))

#capitals.pop('China')
#capitals.clear()
#for key,value in capitals.items():
#   print(key,value)

phonebook = {}
phonebook["John"] = 123456789
phonebook["Matt"] = 1234
print(phonebook)