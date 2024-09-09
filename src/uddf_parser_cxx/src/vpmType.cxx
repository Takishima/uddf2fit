// Copyright (c) 2005-2023 Code Synthesis.
//
// This program was generated by CodeSynthesis XSD, an XML Schema to
// C++ data binding compiler.
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License version 2 as
// published by the Free Software Foundation.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
//
// In addition, as a special exception, Code Synthesis gives permission
// to link this program with the Xerces-C++ library (or with modified
// versions of Xerces-C++ that use the same license as Xerces-C++), and
// distribute linked combinations including the two. You must obey the GNU
// General Public License version 2 in all respects for all of the code
// used other than Xerces-C++. If you modify this copy of the program, you
// may extend this exception to your version of the program, but you are
// not obligated to do so. If you do not wish to do so, delete this
// exception statement from your version.
//
// Furthermore, Code Synthesis makes a special exception for the Free/Libre
// and Open Source Software (FLOSS) which is described in the accompanying
// FLOSSE file.
//

// Begin prologue.
//
//
// End prologue.

#include <xsd/cxx/pre.hxx>

#include "vpmType.hxx"

#include "ID.hxx"

#include "tissueType.hxx"

namespace streit
{
  // vpmType
  //

  const vpmType::gamma_optional& vpmType::
  gamma () const
  {
    return this->gamma_;
  }

  vpmType::gamma_optional& vpmType::
  gamma ()
  {
    return this->gamma_;
  }

  void vpmType::
  gamma (const gamma_type& x)
  {
    this->gamma_.set (x);
  }

  void vpmType::
  gamma (const gamma_optional& x)
  {
    this->gamma_ = x;
  }

  const vpmType::gc_optional& vpmType::
  gc () const
  {
    return this->gc_;
  }

  vpmType::gc_optional& vpmType::
  gc ()
  {
    return this->gc_;
  }

  void vpmType::
  gc (const gc_type& x)
  {
    this->gc_.set (x);
  }

  void vpmType::
  gc (const gc_optional& x)
  {
    this->gc_ = x;
  }

  const vpmType::lambda_optional& vpmType::
  lambda () const
  {
    return this->lambda_;
  }

  vpmType::lambda_optional& vpmType::
  lambda ()
  {
    return this->lambda_;
  }

  void vpmType::
  lambda (const lambda_type& x)
  {
    this->lambda_.set (x);
  }

  void vpmType::
  lambda (const lambda_optional& x)
  {
    this->lambda_ = x;
  }

  const vpmType::r0_optional& vpmType::
  r0 () const
  {
    return this->r0_;
  }

  vpmType::r0_optional& vpmType::
  r0 ()
  {
    return this->r0_;
  }

  void vpmType::
  r0 (const r0_type& x)
  {
    this->r0_.set (x);
  }

  void vpmType::
  r0 (const r0_optional& x)
  {
    this->r0_ = x;
  }

  const vpmType::tissue_sequence& vpmType::
  tissue () const
  {
    return this->tissue_;
  }

  vpmType::tissue_sequence& vpmType::
  tissue ()
  {
    return this->tissue_;
  }

  void vpmType::
  tissue (const tissue_sequence& s)
  {
    this->tissue_ = s;
  }
}

#include <xsd/cxx/xml/dom/parsing-source.hxx>

namespace streit
{
  // vpmType
  //

  vpmType::
  vpmType (const id_type& id)
  : ::streit::ID_TYPE (id),
    gamma_ (this),
    gc_ (this),
    lambda_ (this),
    r0_ (this),
    tissue_ (this)
  {
  }

  vpmType::
  vpmType (const vpmType& x,
           ::xml_schema::flags f,
           ::xml_schema::container* c)
  : ::streit::ID_TYPE (x, f, c),
    gamma_ (x.gamma_, f, this),
    gc_ (x.gc_, f, this),
    lambda_ (x.lambda_, f, this),
    r0_ (x.r0_, f, this),
    tissue_ (x.tissue_, f, this)
  {
  }

  vpmType::
  vpmType (const ::xercesc::DOMElement& e,
           ::xml_schema::flags f,
           ::xml_schema::container* c)
  : ::streit::ID_TYPE (e, f | ::xml_schema::flags::base, c),
    gamma_ (this),
    gc_ (this),
    lambda_ (this),
    r0_ (this),
    tissue_ (this)
  {
    if ((f & ::xml_schema::flags::base) == 0)
    {
      ::xsd::cxx::xml::dom::parser< char > p (e, true, false, true);
      this->parse (p, f);
    }
  }

  void vpmType::
  parse (::xsd::cxx::xml::dom::parser< char >& p,
         ::xml_schema::flags f)
  {
    this->::streit::ID_TYPE::parse (p, f);

    for (; p.more_content (); p.next_content (false))
    {
      const ::xercesc::DOMElement& i (p.cur_element ());
      const ::xsd::cxx::xml::qualified_name< char > n (
        ::xsd::cxx::xml::dom::name< char > (i));

      // gamma
      //
      if (n.name () == "gamma" && n.namespace_ () == "http://www.streit.cc/uddf/3.2/")
      {
        if (!this->gamma_)
        {
          this->gamma_.set (gamma_traits::create (i, f, this));
          continue;
        }
      }

      // gc
      //
      if (n.name () == "gc" && n.namespace_ () == "http://www.streit.cc/uddf/3.2/")
      {
        if (!this->gc_)
        {
          this->gc_.set (gc_traits::create (i, f, this));
          continue;
        }
      }

      // lambda
      //
      if (n.name () == "lambda" && n.namespace_ () == "http://www.streit.cc/uddf/3.2/")
      {
        if (!this->lambda_)
        {
          this->lambda_.set (lambda_traits::create (i, f, this));
          continue;
        }
      }

      // r0
      //
      if (n.name () == "r0" && n.namespace_ () == "http://www.streit.cc/uddf/3.2/")
      {
        if (!this->r0_)
        {
          this->r0_.set (r0_traits::create (i, f, this));
          continue;
        }
      }

      // tissue
      //
      if (n.name () == "tissue" && n.namespace_ () == "http://www.streit.cc/uddf/3.2/")
      {
        ::std::unique_ptr< tissue_type > r (
          tissue_traits::create (i, f, this));

        this->tissue_.push_back (::std::move (r));
        continue;
      }

      break;
    }
  }

  vpmType* vpmType::
  _clone (::xml_schema::flags f,
          ::xml_schema::container* c) const
  {
    return new class vpmType (*this, f, c);
  }

  vpmType& vpmType::
  operator= (const vpmType& x)
  {
    if (this != &x)
    {
      static_cast< ::streit::ID_TYPE& > (*this) = x;
      this->gamma_ = x.gamma_;
      this->gc_ = x.gc_;
      this->lambda_ = x.lambda_;
      this->r0_ = x.r0_;
      this->tissue_ = x.tissue_;
    }

    return *this;
  }

  vpmType::
  ~vpmType ()
  {
  }
}

#include <ostream>

namespace streit
{
  ::std::ostream&
  operator<< (::std::ostream& o, const vpmType& i)
  {
    o << static_cast< const ::streit::ID_TYPE& > (i);

    if (i.gamma ())
    {
      o << ::std::endl << "gamma: " << *i.gamma ();
    }

    if (i.gc ())
    {
      o << ::std::endl << "gc: " << *i.gc ();
    }

    if (i.lambda ())
    {
      o << ::std::endl << "lambda: " << *i.lambda ();
    }

    if (i.r0 ())
    {
      o << ::std::endl << "r0: " << *i.r0 ();
    }

    for (vpmType::tissue_const_iterator
         b (i.tissue ().begin ()), e (i.tissue ().end ());
         b != e; ++b)
    {
      o << ::std::endl << "tissue: " << *b;
    }

    return o;
  }
}

#include <istream>
#include <xsd/cxx/xml/sax/std-input-source.hxx>
#include <xsd/cxx/tree/error-handler.hxx>

namespace streit
{
}

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

