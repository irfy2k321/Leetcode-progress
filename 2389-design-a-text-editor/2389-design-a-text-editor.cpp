class TextEditor {

private:
    string text; // Store the entire text
    int cursor;  // Position of the cursor

public:
    // Constructor to initialize empty text and cursor at 0
    TextEditor() : text(""), cursor(0) {}

    // Adds the given text at the current cursor position
    void addText(string newText) {
        text.insert(cursor, newText);
        cursor += newText.length(); // Move cursor to the right of added text
    }
    
    // Deletes 'k' characters to the left of the cursor
    int deleteText(int k) {
        int deleteCount = min(k, cursor); // Limit deletion to available characters
        text.erase(cursor - deleteCount, deleteCount);
        cursor -= deleteCount; // Move cursor left after deletion
        return deleteCount;    // Return how many characters were deleted
    }
    
    // Moves the cursor 'k' positions to the left
    string cursorLeft(int k) {
        cursor = max(0, cursor - k); // Update cursor position
        return text.substr(max(0, cursor - 10), min(10, cursor)); // Return last 10 characters to the left of the cursor
    }
    
    // Moves the cursor 'k' positions to the right
    string cursorRight(int k) {
        cursor = min((int)text.length(), cursor + k); // Update cursor position
        return text.substr(max(0, cursor - 10), min(10, cursor)); // Return last 10 characters to the left of the cursor
    }
};