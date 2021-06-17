#pragma once


// 変数のゲットやセットなどの機能をまとめた構造体
template <class T>
struct Variables {
protected:
	T m_variables;
public:
	inline Variables() {  };
	T Get() { return m_variables; };
	T* GetPtr() { return &m_variables; };
	T& GetAddres() { return m_variables; };
	void Set(T variables) { m_variables = variables; };
};

struct Bool : Variables<bool>
{
public:
	inline Bool(bool flag = true) { m_variables = flag; }
	void On() { m_variables = true; }
	void Off() { m_variables = false; }
	void Reverse() { m_variables = !m_variables; }
	bool IsValid() { return m_variables; };
	bool InValid() { return !m_variables; }
};



template <class T>
struct VariablesPtr {
protected:
	T* m_variables;
public:
	inline VariablesPtr() {  };
	inline VariablesPtr(T* variables) { m_variables = variables; };
	T Get() { return *m_variables; };
	T* GetPtr() { return m_variables; };
	T& GetAddres() { return *m_variables; };
	void Set(T* variables) { m_variables = variables; };
	T* NullCheck() { return (m_variables == nullptr); }
};

struct BoolPtr : VariablesPtr<bool>
{
public:
	inline BoolPtr() {}
	void On() { *m_variables = true; }
	void Off() { *m_variables = false; }
	void Reverse() { *m_variables = !*m_variables; }
	bool IsValid() { return *m_variables; };
	bool InValid() { return !*m_variables; }
};
