#ifndef X64_SRC_CODE_OPERAND_H
#define X64_SRC_CODE_OPERAND_H

#include <iostream>
#include <stdint.h>

namespace x64 {

/** Base operand type. */
class Operand {
	public:
		virtual ~Operand() = 0; 

		virtual bool check() const = 0;

		virtual void write_att(std::ostream& os) const = 0;
		virtual void write_intel(std::ostream& os) const = 0;
};

/** Atomic Operand Type. */
class AtomicOperand : public Operand {
	public:
		inline AtomicOperand(uint64_t val) : val_{val} { }
		virtual ~AtomicOperand() = 0;

		virtual bool check() const;

		virtual void write_att(std::ostream& os) const = 0;
		virtual void write_intel(std::ostream& os) const = 0;

		inline uint64_t val() const {
			return val_;
		}
			
	private:
		uint64_t val_;	
};

/** Aggregate Operand Type. */
class CompoundOperand : public Operand {
	public:
		virtual ~CompoundOperand() = 0;

		virtual bool check() const = 0;

		virtual void write_att(std::ostream& os) const = 0;
		virtual void write_intel(std::ostream& os) const = 0;
};

} // namespace x64

#endif