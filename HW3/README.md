# Doubly_Linked_List

### Spec :

    In this homework, your goal is to implement a link list class 
    that allows inserting, deleting, and editing data in the structure. 
    
    You can consider the case study of Array class shown in the course slides 
    and implement the link list structure.

### Introduction :
   
   ####  this code is implemented with "template"!
   
    there are two friend functions : 
    operator >> and << which overloaded istream and ostream in the class.
    
    there are also two public funtions overloading operator [],
    just as treating the linked-list as an array, if we want to retrive the value in nth node,
    simply use ll[n].
   	
### Problem and How I Solved :
    
    TA asked us to separate the definition and declaration,
    meaning definition should be in header file(.h) and declaration should be in source file(.cpp). 
    
    But after I implemented all funtions in source file, the compiler showed a list of error messages :
    [Linker error] undifined reference to '...', thus, I turned to implement the funtions in header file,
    and all testdatas are correct.
    
    and I finally found that : 
    
 #### Class and "Every" friend funtion need to be defined in cpp file.
   
   after I add the following code in the end of source file, all testdatas are correct. :)
   
    template class Link_List<int>;
    template ostream & operator <<(ostream &, const Link_List<int> &);
    template istream & operator >>(istream &, Link_List<int> &); 
    
 #### in this case, we assume typename is int, when we need to implement other types, we should re-define above code with corresponding types!
 
  reference :
  https://stackoverflow.com/questions/495021/why-can-templates-only-be-implemented-in-the-header-file
