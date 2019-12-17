#pragma once

class ComponentManager
{
private:
	ComponentManager();

public:
	~ComponentManager();

	static void InitAll(void);
	static void UninitAll(void);
	static void ProcessInputAll(void);
	static void UpdateAll(void);
	static void GenerateOutputAll(void);

private:

};

