package mypkg;

public class Foo {
	

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		System.out.println("Hello World");
		
		System.out.println("");
		System.out.println("ParseFloat");
		do_ParseFloat();
		
		System.out.println("");
		System.out.println("Constants");
		do_Constants();
		
		System.out.println("");
		System.out.println("NaNInfinity");
		do_NaNInfinity();
		
		System.out.println("");
		System.out.println("Extremes");
		do_Extremes();
		
		
	}
	
	public static void do_Constants() throws Exception
	{
		testConstants(0);
		testConstants(1);
		testConstants(2);
		testConstants(-126);
		testConstants(127);
		testConstants(Integer.MAX_VALUE - 1);
		testConstants(Integer.MAX_VALUE);
		testConstants(Integer.MIN_VALUE);

	}
	
    public static void testConstants(int i) throws Exception {
        switch (i) {
        case (int)Float.NaN:                    // 0
            System.out.println(i+":Float.NaN is a constant!");
            break;
        case (int)Float.MIN_VALUE + 1:          // 0 + 1
            System.out.println(i+":Float.MIN_VALUE is a constant!");
            break;
        case (int)Float.MIN_NORMAL + 2:         // 0 + 2
            System.out.println(i+":Float.MIN_NORMAL is a constant!");
            break;
        case Float.MIN_EXPONENT:                // -126
            System.out.println(i+": Float.MIN_EXPONENT is a constant!");
            break;
        case Float.MAX_EXPONENT:                // 127
            System.out.println(i+":Float.MAX_EXPONENT is a constant!");
            break;
        case (int)Float.MAX_VALUE - 1:          // Integer.MAX_VALUE - 1
            System.out.println(i+":Float.MAX_VALUE is a constant!");
            break;
        case (int)Float.POSITIVE_INFINITY:      // Integer.MAX_VALUE
            System.out.println(i+":Float.POSITIVE_INFINITY is a constant!");
            break;
        case (int)Float.NEGATIVE_INFINITY:      // Integer.MIN_VALUE
            System.out.println(i+":Float.NEGATIVE_INFINITY is a constant!");
            break;
        }
    }
	
    /* Check extreems */
    public static void do_Extremes() throws Exception {
        if (Float.MIN_VALUE != Float.intBitsToFloat(0x1)){
        	System.out.println("Float.MIN_VALUE is not equal to intBitsToFloat(0x1).");
        }
        else
        {
        	System.out.println("Float.MIN_VALUE is equal to intBitsToFloat(0x1).");
        }
        if (Float.MIN_NORMAL != Float.intBitsToFloat(0x00800000)){
        	System.out.println("Float.MIN_NORMAL is not equal to intBitsToFloat(0x00800000).");
        }
        else
        {
        	System.out.println("Float.MIN_NORMAL is equal to intBitsToFloat(0x00800000).");
        }
        if (Float.MAX_VALUE != Float.intBitsToFloat(0x7f7fffff)){
        	System.out.println("Float.MAX_VALUE is not equal to intBitsToFloat(0x7f7fffff).");
        }
        else
        {
        	System.out.println("Float.MAX_VALUE is equal to intBitsToFloat(0x7f7fffff).");
        }
    }
    
    /* check parsing */
    private static void check(String val, float expected) {
        float n = Float.parseFloat(val);
        if (n != expected)
        {
        	System.out.println("Float.parseFloat failed. String:" + val + " Result:" + n);
        }
        else
        {
        	System.out.println("Float.parseFloat successful. String:" + val + " Result:" + n);
        }
    }

    private static void rudimentaryTest() {
        check(new String(""+Float.MIN_VALUE), Float.MIN_VALUE);
        check(new String(""+Float.MAX_VALUE), Float.MAX_VALUE);

        check("10",     (float)  10.0);
        check("10.0",   (float)  10.0);
        check("10.01",  (float)  10.01);

        check("-10",    (float) -10.0);
        check("-10.00", (float) -10.0);
        check("-10.01", (float) -10.01);
    }


    static  String badStrings[] = {
        "",
        "+",
        "-",
        "+e",
        "-e",
        "+e170",
        "-e170",

        // Make sure intermediate white space is not deleted.
        "1234   e10",
        "-1234   e10",

        // Control characters in the interior of a string are not legal
        "1\u0007e1",
        "1e\u00071",

        // NaN and infinity can't have trailing type suffices or exponents
        "NaNf",
        "NaNF",
        "NaNd",
        "NaND",
        "-NaNf",
        "-NaNF",
        "-NaNd",
        "-NaND",
        "+NaNf",
        "+NaNF",
        "+NaNd",
        "+NaND",
        "Infinityf",
        "InfinityF",
        "Infinityd",
        "InfinityD",
        "-Infinityf",
        "-InfinityF",
        "-Infinityd",
        "-InfinityD",
        "+Infinityf",
        "+InfinityF",
        "+Infinityd",
        "+InfinityD",

        "NaNe10",
        "-NaNe10",
        "+NaNe10",
        "Infinitye10",
        "-Infinitye10",
        "+Infinitye10",

        // Non-ASCII digits are not recognized
        "\u0661e\u0661", // 1e1 in Arabic-Indic digits
        "\u06F1e\u06F1", // 1e1 in Extended Arabic-Indic digits
        "\u0967e\u0967" // 1e1 in Devanagari digits
    };

    static String goodStrings[] = {
        "NaN",
        "+NaN",
        "-NaN",
        "Infinity",
        "+Infinity",
        "-Infinity",
        "1.1e-23f",
        ".1e-23f",
        "1e-23",
        "1f",
        "1",
        "2",
        "1234",
        "-1234",
        "+1234",
        "2147483647",   // Integer.MAX_VALUE
        "2147483648",
        "-2147483648",  // Integer.MIN_VALUE
        "-2147483649",

        "16777215",
        "16777216",     // 2^24
        "16777217",

        "-16777215",
        "-16777216",    // -2^24
        "-16777217",

        "9007199254740991",
        "9007199254740992",     // 2^53
        "9007199254740993",

        "-9007199254740991",
        "-9007199254740992",    // -2^53
        "-9007199254740993",

        "9223372036854775807",
        "9223372036854775808",  // Long.MAX_VALUE
        "9223372036854775809",

        "-9223372036854775808",
        "-9223372036854775809", // Long.MIN_VALUE
        "-9223372036854775810"
    };

    static String paddedBadStrings[];
    static String paddedGoodStrings[];
    static {
        String pad = " \t\n\r\f\u0001\u000b\u001f";
        paddedBadStrings = new String[badStrings.length];
        for(int i = 0 ; i <  badStrings.length; i++)
            paddedBadStrings[i] = pad + badStrings[i] + pad;

        paddedGoodStrings = new String[goodStrings.length];
        for(int i = 0 ; i <  goodStrings.length; i++)
            paddedGoodStrings[i] = pad + goodStrings[i] + pad;

    }

    /*
     * Throws an exception if <code>Input</code> is
     * <code>exceptionalInput</code> and {@link Float.parseFloat
     * parseFloat} does <em>not</em> throw an exception or if
     * <code>Input</code> is not <code>exceptionalInput</code> and
     * <code>parseFloat</code> throws an exception.  This method does
     * not attempt to test whether the string is converted to the
     * proper value; just whether the input is accepted appropriately
     * or not.
     */
    private static void testParsing(String [] input, boolean exceptionalInput) {
        for(int i = 0; i < input.length; i++) {
            
        	double d;

            try {
                d = Float.parseFloat(input[i]);
            }
            catch (NumberFormatException e) {
                if (! exceptionalInput) {
                	System.out.println("Float.parseFloat rejected " +
                                               "good string `" + input[i] +
                                               "'.");
                }
                break;
            }
            if (exceptionalInput) {
            	System.out.println("Float.parseFloat accepted " +
                                           "bad string `" + input[i] +
                                           "'.");
            }
        }
    }

    public static void do_ParseFloat() throws Exception {
        
    	rudimentaryTest();

        testParsing(goodStrings, false);
        testParsing(paddedGoodStrings, false);
        testParsing(badStrings, true);
        testParsing(paddedBadStrings, true);
    }
    
    /* NaNInfinity check */
    
    static String NaNStrings[] = {
        "NaN",
        "+NaN",
        "-NaN"
    };

    static String infinityStrings[] = {
        "Infinity",
        "+Infinity",
        "-Infinity",
    };

    static String invalidStrings[] = {
        "+",
        "-",
        "@",
        "N",
        "Na",
        "Nan",
        "NaNf",
        "NaNd",
        "NaNF",
        "NaND",
        "+N",
        "+Na",
        "+Nan",
        "+NaNf",
        "+NaNd",
        "+NaNF",
        "+NaND",
        "-N",
        "-Na",
        "-Nan",
        "-NaNf",
        "-NaNd",
        "-NaNF",
        "-NaND",
        "I",
        "In",
        "Inf",
        "Infi",
        "Infin",
        "Infini",
        "Infinit",
        "InfinitY",
        "Infinityf",
        "InfinityF",
        "Infinityd",
        "InfinityD",
        "+I",
        "+In",
        "+Inf",
        "+Infi",
        "+Infin",
        "+Infini",
        "+Infinit",
        "+InfinitY",
        "+Infinityf",
        "+InfinityF",
        "+Infinityd",
        "+InfinityD",
        "-I",
        "-In",
        "-Inf",
        "-Infi",
        "-Infin",
        "-Infini",
        "-Infinit",
        "-InfinitY",
        "-Infinityf",
        "-InfinityF",
        "-Infinityd",
        "-InfinityD",
        "NaNInfinity",
        "InfinityNaN",
        "nan",
        "infinity"
    };

    public static void do_NaNInfinity() throws Exception {
        int i;
        float d;

        // Test valid NaN strings
        for(i = 0; i < NaNStrings.length; i++) {
            d=Float.parseFloat(NaNStrings[i]);
            if(!Float.isNaN(d)) {
            	System.out.println("NaN string ``" + NaNStrings[i]
                                           + "'' did not parse as a NaN; returned " +
                                           d + " instead.");
            }
            else
            {
            	System.out.println("NaN string ``" + NaNStrings[i]
                        + "'' parsed as a NaN");
            }
        }

        // Test valid Infinity strings
        for(i = 0; i < infinityStrings.length; i++) {
            if(!Float.isInfinite(d=Float.parseFloat(infinityStrings[i]))) {
            	System.out.println("Infinity string ``" +
                                           infinityStrings[i] +
                                           "'' did not parse as infinity; returned " +
                                           d + "instead.");
            }
            else
            {
            	System.out.println("Infinity string ``" +
                        infinityStrings[i] +
                        "'' parsed as infinity.");
            }
            // check sign of result

            boolean negative = (infinityStrings[i].charAt(0) == '-');
            if(d != (negative?Float.NEGATIVE_INFINITY:
                          Float.POSITIVE_INFINITY))
            {
            	System.out.println("Infinity has wrong sign;" +
                                           (negative?"positive instead of negative.":
                                            "negative instead of positive."));
            }
            else
            {
            	System.out.println("Infinity has right sign.");
            }
        }

        // Test almost valid strings
        for(i = 0; i < invalidStrings.length; i++) {
            try {
                float result;
                d = Float.parseFloat(invalidStrings[i]);
                System.out.println("Invalid string ``" +
                                           invalidStrings[i]
                                           +"'' parsed as " + d + ".");
            }
            catch(NumberFormatException e) {
                // expected
            	System.out.println("String '"+invalidStrings[i]+"' parsed as expeted.");
            }
        }

    }

    
	
}
