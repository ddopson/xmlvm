package java.util.regex;


public final class Matcher {

    Pattern parentPattern;
    int[] groups;
    int from, to;

    int lookbehindTo;

    CharSequence text;

    static final int ENDANCHOR = 1;
    static final int NOANCHOR = 0;
    int acceptMode = NOANCHOR;
    int first = -1, last = 0;

    int oldLast = -1;

    int lastAppendPosition = 0;

    int[] locals;

    boolean hitEnd;

    boolean requireEnd;

    boolean transparentBounds = false;
    boolean anchoringBounds = true;

    Matcher() {
    }

    Matcher(Pattern parent, CharSequence text) { throw new RuntimeException("Not Implemented: 'toString'"); }    

    public Pattern pattern() {
        return parentPattern;
    }

    public MatchResult toMatchResult() { throw new RuntimeException("Not Implemented: 'toString'"); }
    public Matcher usePattern(Pattern newPattern) { throw new RuntimeException("Not Implemented: 'toString'"); }

    public Matcher reset() { throw new RuntimeException("Not Implemented: 'toString'"); }
    public Matcher reset(CharSequence input) { throw new RuntimeException("Not Implemented: 'toString'"); }

    public int start() { throw new RuntimeException("Not Implemented: 'toString'"); }

    public int end() { throw new RuntimeException("Not Implemented: 'toString'"); }
    public String group() { throw new RuntimeException("Not Implemented: 'toString'"); }

    public String group(int group) { throw new RuntimeException("Not Implemented: 'toString'"); }

    public String group(String name) { throw new RuntimeException("Not Implemented: 'toString'"); }

    public int groupCount() { throw new RuntimeException("Not Implemented: 'toString'"); }
    public boolean matches() { throw new RuntimeException("Not Implemented: 'toString'"); }

    public boolean find() { throw new RuntimeException("Not Implemented: 'toString'"); }

    public boolean find(int start) { throw new RuntimeException("Not Implemented: 'toString'"); }

    public boolean lookingAt() { throw new RuntimeException("Not Implemented: 'toString'"); }

    public String toString() { throw new RuntimeException("Not Implemented: 'toString'"); }

}
