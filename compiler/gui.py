import os
import subprocess
import tkinter as tk
from tkinter import filedialog, scrolledtext, messagebox
from ctypes import windll

# Fix blurry UI on Windows
windll.shcore.SetProcessDpiAwareness(1)


PROJECT_PATH = r"E:\Shiv\SimpleLang"
COMPILER_PATH = os.path.join(PROJECT_PATH, "compiler")
EXE_PATH = os.path.join(COMPILER_PATH, "simpleLang.exe")
VM_PATH = os.path.join(COMPILER_PATH, "vm.exe")
SOURCE_FILE = ""

class CompilerGUI:
    def __init__(self, root):
        self.root = root
        root.title("SimpleLang IDE")
        root.geometry("1100x600")
        root.configure(bg="#1e1e1e")

        # --- Top Frame ---
        top_frame = tk.Frame(root, bg="#1e1e1e")
        top_frame.pack(pady=10, fill=tk.X)

        self.file_label = tk.Label(top_frame, text="No file selected", fg="white", bg="#1e1e1e", font=("Consolas", 10))
        self.file_label.pack(side=tk.LEFT, padx=10)

        tk.Button(top_frame, text="Choose .sp File", command=self.select_file, bg="#007acc", fg="white").pack(side=tk.LEFT, padx=5)
        tk.Button(top_frame, text="Compile", command=self.compile_code, bg="#007acc", fg="white").pack(side=tk.LEFT, padx=5)
        tk.Button(top_frame, text="Run VM", command=self.run_vm, bg="#28a745", fg="white").pack(side=tk.LEFT, padx=5)

        # --- Output Frames ---
        output_frame = tk.Frame(root, bg="#1e1e1e")
        output_frame.pack(fill=tk.BOTH, expand=True, padx=10, pady=5)

        # Left - OUTPUT
        left_frame = tk.Frame(output_frame, bg="#1e1e1e")
        left_frame.pack(side=tk.LEFT, fill=tk.BOTH, expand=True, padx=5)

        tk.Label(left_frame, text="OUTPUT:", fg="#61dafb", bg="#1e1e1e", font=("Consolas", 11, "bold")).pack(anchor="w")

        self.output_box = scrolledtext.ScrolledText(left_frame, wrap=tk.WORD, font=("Courier New", 10),
                                                    bg="#252526", fg="#d4d4d4", insertbackground="white")
        self.output_box.pack(fill=tk.BOTH, expand=True)

        # Right - SYMBOL TABLE
        right_frame = tk.Frame(output_frame, bg="#1e1e1e")
        right_frame.pack(side=tk.RIGHT, fill=tk.BOTH, expand=True, padx=5)

        tk.Label(right_frame, text="THREE ADDRESS CODE:", fg="#ffb86c", bg="#1e1e1e", font=("Consolas", 11, "bold")).pack(anchor="w")

        self.symbol_box = scrolledtext.ScrolledText(right_frame, wrap=tk.WORD, font=("Courier New", 10),
                                                    bg="#252526", fg="#d4d4d4", insertbackground="white")
        self.symbol_box.pack(fill=tk.BOTH, expand=True)

        # Status bar
        self.status = tk.Label(root, text="Ready", fg="white", bg="#007acc", anchor=tk.W)
        self.status.pack(fill=tk.X, side=tk.BOTTOM)

    def select_file(self):
        global SOURCE_FILE
        file_path = filedialog.askopenfilename(initialdir=PROJECT_PATH, filetypes=[("SimpleLang", "*.sp")])
        if file_path:
            SOURCE_FILE = file_path
            self.file_label.config(text=SOURCE_FILE)
            self.status.config(text="File selected.")
        else:
            self.status.config(text="No file selected.")

    def compile_code(self):
        if not SOURCE_FILE:
            messagebox.showerror("Error", "No .sp file selected.")
            return

        self.output_box.delete(1.0, tk.END)
        self.symbol_box.delete(1.0, tk.END)
        self.status.config(text="Compiling...")

        try:
            subprocess.run([EXE_PATH, SOURCE_FILE], cwd=COMPILER_PATH, check=True)
            subprocess.run(["gcc", "vm.c", "-o", "vm"], cwd=COMPILER_PATH, check=True)
            self.status.config(text="Compilation successful.")
            self.output_box.insert(tk.END, "[✔] Compilation completed.\n")
        except subprocess.CalledProcessError as e:
            self.status.config(text="Compilation failed.")
            self.output_box.insert(tk.END, f"[✖] Compilation error:\n{e}\n")

    def run_vm(self):
        self.output_box.insert(tk.END, "\n[▶] Running VM...\n")
        try:
            result = subprocess.run([VM_PATH, "output.icg"], cwd=COMPILER_PATH, text=True, capture_output=True)
            self.output_box.insert(tk.END, result.stdout)
            self.status.config(text="VM executed successfully.")

            # Load symbol table
            sym_path = os.path.join(COMPILER_PATH, "output.icg")
            if os.path.exists(sym_path):
                with open(sym_path, "r") as f:
                    self.symbol_box.delete(1.0, tk.END)
                    self.symbol_box.insert(tk.END, f.read())
            else:
                self.symbol_box.insert(tk.END, "[!] symbol_table.txt not found.")
        except Exception as e:
            self.output_box.insert(tk.END, f"[✖] VM error: {e}\n")
            self.status.config(text="VM failed.")

if __name__ == "__main__":
    root = tk.Tk()
    CompilerGUI(root)
    root.mainloop()
