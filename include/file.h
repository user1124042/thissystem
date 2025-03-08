#ifndef _FILE_H
#define _FILE_H

#include <string>

class File {
   public:
    explicit File(const std::string& FileNames, bool* IsNew = nullptr) {
        if (IsNew) {
            *IsNew = false;

            if (fopen(FileNames.c_str(), "r") == nullptr) *IsNew = true;
        }

        this->FilePtr = fopen(FileNames.c_str(), "w+");
        this->FileName = FileNames;
    }

    ~File() {
        if (FilePtr) {
            fclose(FilePtr);
        }
    }

    [[nodiscard]] bool Write(std::string& str) const {
        if (FilePtr) {
            if (!str.empty() && str[0] == '\n')
                str.erase(0, str.find_first_not_of('\n'));
            fprintf(this->FilePtr, "%s", str.c_str());
        } else {
            return false;
        }
        return true;
    }

    [[nodiscard]] FILE* GetFilePtr() const { return FilePtr; }

   private:
    std::string FileName;
    FILE* FilePtr;
};

#endif