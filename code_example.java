class code_example {
    public static void main(String[] args) {
        System.out.println("Testing arithmetic");

        String string_var = "String " + "variable";
        string_var = string_var + " named string_var";

        Integer integer_var = 1 + ((2 * 3) + (9 - 3)) / 5;
        integer_var = integer_var - 555;

        Boolean bool_var = (integer_var < 0) || (integer_var == 0);
        bool_var = (bool_var || !bool_var) && bool_var;

        System.out.println("Success!");

        System.out.println("--------------------");
        System.out.println("Testing if");

        if (bool_var || !bool_var) {
            System.out.println("Condition is true");
        } else {
            System.out.println("Condition is false");
        }

        Integer if_var = 4;
        if (if_var < 4) {
            System.out.println("cond_var < 4");
        } else if (if_var > 4) {
            System.out.println("cond_var > 4");
        } else {
            System.out.println("cond_var == 4");
        }

        System.out.println("Success!");

        System.out.println("--------------------");
        System.out.println("Testing while");

        Integer while_counter = 5;
        while (while_counter < 10) {
            System.out.print("counter == ");
            System.out.println(while_counter);
            while_counter = while_counter + 1;
        }
        
        System.out.println("Success!");

        System.out.println("--------------------");
        System.out.println("Testing for");

        Integer for_var = 1;
        for (; for_var < 10; for_var = for_var + 1) {
            System.out.print("counter == ");
            System.out.println(for_var);
        }

        System.out.print("Success!");
    }
}
