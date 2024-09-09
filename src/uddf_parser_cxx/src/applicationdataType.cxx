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

#include "applicationdataType.hxx"

#include "decotrainer.hxx"

#include "hargikas.hxx"

#include "heinrichsweikamp.hxx"

#include "tausim.hxx"

#include "tautabu.hxx"

namespace streit
{
  // applicationdataType
  //

  const applicationdataType::decotrainer_optional& applicationdataType::
  decotrainer () const
  {
    return this->decotrainer_;
  }

  applicationdataType::decotrainer_optional& applicationdataType::
  decotrainer ()
  {
    return this->decotrainer_;
  }

  void applicationdataType::
  decotrainer (const decotrainer_type& x)
  {
    this->decotrainer_.set (x);
  }

  void applicationdataType::
  decotrainer (const decotrainer_optional& x)
  {
    this->decotrainer_ = x;
  }

  void applicationdataType::
  decotrainer (::std::unique_ptr< decotrainer_type > x)
  {
    this->decotrainer_.set (std::move (x));
  }

  const applicationdataType::hargikas_optional& applicationdataType::
  hargikas () const
  {
    return this->hargikas_;
  }

  applicationdataType::hargikas_optional& applicationdataType::
  hargikas ()
  {
    return this->hargikas_;
  }

  void applicationdataType::
  hargikas (const hargikas_type& x)
  {
    this->hargikas_.set (x);
  }

  void applicationdataType::
  hargikas (const hargikas_optional& x)
  {
    this->hargikas_ = x;
  }

  void applicationdataType::
  hargikas (::std::unique_ptr< hargikas_type > x)
  {
    this->hargikas_.set (std::move (x));
  }

  const applicationdataType::heinrichsweikamp_optional& applicationdataType::
  heinrichsweikamp () const
  {
    return this->heinrichsweikamp_;
  }

  applicationdataType::heinrichsweikamp_optional& applicationdataType::
  heinrichsweikamp ()
  {
    return this->heinrichsweikamp_;
  }

  void applicationdataType::
  heinrichsweikamp (const heinrichsweikamp_type& x)
  {
    this->heinrichsweikamp_.set (x);
  }

  void applicationdataType::
  heinrichsweikamp (const heinrichsweikamp_optional& x)
  {
    this->heinrichsweikamp_ = x;
  }

  void applicationdataType::
  heinrichsweikamp (::std::unique_ptr< heinrichsweikamp_type > x)
  {
    this->heinrichsweikamp_.set (std::move (x));
  }

  const applicationdataType::tausim_optional& applicationdataType::
  tausim () const
  {
    return this->tausim_;
  }

  applicationdataType::tausim_optional& applicationdataType::
  tausim ()
  {
    return this->tausim_;
  }

  void applicationdataType::
  tausim (const tausim_type& x)
  {
    this->tausim_.set (x);
  }

  void applicationdataType::
  tausim (const tausim_optional& x)
  {
    this->tausim_ = x;
  }

  void applicationdataType::
  tausim (::std::unique_ptr< tausim_type > x)
  {
    this->tausim_.set (std::move (x));
  }

  const applicationdataType::tautabu_optional& applicationdataType::
  tautabu () const
  {
    return this->tautabu_;
  }

  applicationdataType::tautabu_optional& applicationdataType::
  tautabu ()
  {
    return this->tautabu_;
  }

  void applicationdataType::
  tautabu (const tautabu_type& x)
  {
    this->tautabu_.set (x);
  }

  void applicationdataType::
  tautabu (const tautabu_optional& x)
  {
    this->tautabu_ = x;
  }

  void applicationdataType::
  tautabu (::std::unique_ptr< tautabu_type > x)
  {
    this->tautabu_.set (std::move (x));
  }
}

#include <xsd/cxx/xml/dom/parsing-source.hxx>

namespace streit
{
  // applicationdataType
  //

  applicationdataType::
  applicationdataType ()
  : ::xml_schema::type (),
    decotrainer_ (this),
    hargikas_ (this),
    heinrichsweikamp_ (this),
    tausim_ (this),
    tautabu_ (this)
  {
  }

  applicationdataType::
  applicationdataType (const applicationdataType& x,
                       ::xml_schema::flags f,
                       ::xml_schema::container* c)
  : ::xml_schema::type (x, f, c),
    decotrainer_ (x.decotrainer_, f, this),
    hargikas_ (x.hargikas_, f, this),
    heinrichsweikamp_ (x.heinrichsweikamp_, f, this),
    tausim_ (x.tausim_, f, this),
    tautabu_ (x.tautabu_, f, this)
  {
  }

  applicationdataType::
  applicationdataType (const ::xercesc::DOMElement& e,
                       ::xml_schema::flags f,
                       ::xml_schema::container* c)
  : ::xml_schema::type (e, f | ::xml_schema::flags::base, c),
    decotrainer_ (this),
    hargikas_ (this),
    heinrichsweikamp_ (this),
    tausim_ (this),
    tautabu_ (this)
  {
    if ((f & ::xml_schema::flags::base) == 0)
    {
      ::xsd::cxx::xml::dom::parser< char > p (e, true, false, false);
      this->parse (p, f);
    }
  }

  void applicationdataType::
  parse (::xsd::cxx::xml::dom::parser< char >& p,
         ::xml_schema::flags f)
  {
    for (; p.more_content (); p.next_content (false))
    {
      const ::xercesc::DOMElement& i (p.cur_element ());
      const ::xsd::cxx::xml::qualified_name< char > n (
        ::xsd::cxx::xml::dom::name< char > (i));

      // decotrainer
      //
      if (n.name () == "decotrainer" && n.namespace_ () == "http://www.streit.cc/uddf/3.2/")
      {
        ::std::unique_ptr< decotrainer_type > r (
          decotrainer_traits::create (i, f, this));

        if (!this->decotrainer_)
        {
          this->decotrainer_.set (::std::move (r));
          continue;
        }
      }

      // hargikas
      //
      if (n.name () == "hargikas" && n.namespace_ () == "http://www.streit.cc/uddf/3.2/")
      {
        ::std::unique_ptr< hargikas_type > r (
          hargikas_traits::create (i, f, this));

        if (!this->hargikas_)
        {
          this->hargikas_.set (::std::move (r));
          continue;
        }
      }

      // heinrichsweikamp
      //
      if (n.name () == "heinrichsweikamp" && n.namespace_ () == "http://www.streit.cc/uddf/3.2/")
      {
        ::std::unique_ptr< heinrichsweikamp_type > r (
          heinrichsweikamp_traits::create (i, f, this));

        if (!this->heinrichsweikamp_)
        {
          this->heinrichsweikamp_.set (::std::move (r));
          continue;
        }
      }

      // tausim
      //
      if (n.name () == "tausim" && n.namespace_ () == "http://www.streit.cc/uddf/3.2/")
      {
        ::std::unique_ptr< tausim_type > r (
          tausim_traits::create (i, f, this));

        if (!this->tausim_)
        {
          this->tausim_.set (::std::move (r));
          continue;
        }
      }

      // tautabu
      //
      if (n.name () == "tautabu" && n.namespace_ () == "http://www.streit.cc/uddf/3.2/")
      {
        ::std::unique_ptr< tautabu_type > r (
          tautabu_traits::create (i, f, this));

        if (!this->tautabu_)
        {
          this->tautabu_.set (::std::move (r));
          continue;
        }
      }

      break;
    }
  }

  applicationdataType* applicationdataType::
  _clone (::xml_schema::flags f,
          ::xml_schema::container* c) const
  {
    return new class applicationdataType (*this, f, c);
  }

  applicationdataType& applicationdataType::
  operator= (const applicationdataType& x)
  {
    if (this != &x)
    {
      static_cast< ::xml_schema::type& > (*this) = x;
      this->decotrainer_ = x.decotrainer_;
      this->hargikas_ = x.hargikas_;
      this->heinrichsweikamp_ = x.heinrichsweikamp_;
      this->tausim_ = x.tausim_;
      this->tautabu_ = x.tautabu_;
    }

    return *this;
  }

  applicationdataType::
  ~applicationdataType ()
  {
  }
}

#include <ostream>

namespace streit
{
  ::std::ostream&
  operator<< (::std::ostream& o, const applicationdataType& i)
  {
    if (i.decotrainer ())
    {
      o << ::std::endl << "decotrainer: " << *i.decotrainer ();
    }

    if (i.hargikas ())
    {
      o << ::std::endl << "hargikas: " << *i.hargikas ();
    }

    if (i.heinrichsweikamp ())
    {
      o << ::std::endl << "heinrichsweikamp: " << *i.heinrichsweikamp ();
    }

    if (i.tausim ())
    {
      o << ::std::endl << "tausim: " << *i.tausim ();
    }

    if (i.tautabu ())
    {
      o << ::std::endl << "tautabu: " << *i.tautabu ();
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

