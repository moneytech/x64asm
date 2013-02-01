/*
Copyright 2103 eric schkufza

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#ifndef X64ASM_ENV_REG_H
#define X64ASM_ENV_REG_H

#include <iostream>

namespace x64asm {

class EnvReg {
	public:
		inline EnvReg(uint64_t val) : val_{val} { }
		virtual ~EnvReg() = 0;
		virtual void write_att(std::ostream& os) const = 0;
		virtual void write_intel(std::ostream& os) const = 0;
	private:
		uint64_t val_;
};

class Rip : public EnvReg {
	public:
		inline Rip() : val_{0} { }
		virtual void write_att(std::ostream& os) const;
		virtual void write_intel(std::ostream& os) const;
};

class FpuData : public EnvReg {
	public:
		inline FpuData() : val_{0} { }
		virtual void write_att(std::ostream& os) const;
		virtual void write_intel(std::ostream& os) const;
};

class FpuInstruction : public EnvReg {
	public:
		inline FpuInstruction() : val_{0} { }
		virtual void write_att(std::ostream& os) const;
		virtual void write_intel(std::ostream& os) const;
};

class FpuOpcode : public EnvReg {
	public:
		inline FpuOpcode() : val_{0} { }
		virtual void write_att(std::ostream& os) const;
		virtual void write_intel(std::ostream& os) const;
};

} // namespace x64asm

#endif
